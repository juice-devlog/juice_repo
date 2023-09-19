import tkinter as tk
from tkinter import scrolledtext, messagebox
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import time
import pyperclip
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import subprocess
import shutil
import pyautogui
from wordpress_xmlrpc import Client, WordPressPost
from wordpress_xmlrpc.methods.users import GetUserInfo
from wordpress_xmlrpc.methods import posts

def initialize_driver():
    try:
        shutil.rmtree(r"c:\chrometemp")  #쿠키 / 캐쉬파일 삭제
    except FileNotFoundError:
        pass
    try:
        subprocess.Popen(r'C:\Program Files\Google\Chrome\Application\chrome.exe --remote-debugging-port=9222 --user-data-dir="C:\Users\pwndu\chrome-cookie"')
        option = Options()
        option.add_experimental_option("debuggerAddress", "127.0.0.1:9222")
        driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()), options=option)
        #driver.switch_to.window(driver.window_handles[0])
        #driver.set_window_position(0, 0)
        #driver.set_window_size(500, 500)
        driver.maximize_window()
        return driver
    except Exception as e:
        messagebox.showerror("오류", f"드라이버 초기화 중 오류 발생: {str(e)}")
        
def delete_cache(driver):
    url = 'chrome://settings/clearBrowserData'
    driver.get(url)

    try:
        # 버튼이 로드될 때까지 대기
#         button = driver.find_element(By.XPATH, '//cr-button[@id="clearBrowsingDataConfirm"]')
        # 마우스 이동
        pyautogui.hotkey('win', 'ctrl', 'right')
        pyautogui.moveTo(1150, 850, duration=0.5)

        # 클릭 (왼쪽 버튼)
        pyautogui.click()
        
        pyautogui.hotkey('win', 'ctrl', 'left')
        # 버튼 클릭
#         button.click()
        time.sleep(15)
        driver.close()
    except:
        return

def login_to_coupang(driver, email, password):
    try:
        driver.get("https://login.coupang.com/login/login.pang?rtnUrl=https%3A%2F%2Fpartners.coupang.com%2Fapi%2Fv1%2Fpostlogin")

        email_input = driver.find_element(By.ID, "login-email-input")
        email_input.send_keys(email)

        password_input = driver.find_element(By.ID, "login-password-input")
        password_input.send_keys(password)

        login_button = driver.find_element(By.XPATH, "//button[@class='login__button login__button--submit _loginSubmitButton login__button--submit-rds' and @type='submit']")
        login_button.click()

        time.sleep(3)
        pyautogui.hotkey('win', 'ctrl', 'left')
    except Exception as e:
        messagebox.showerror("오류", f"로그인 중 오류 발생: {str(e)}")
        driver.quit()

def collect_product_info(driver, keyword, repeat, review_min, email, password):
    try:
        keyword_url = f"https://partners.coupang.com/#affiliate/ws/link/0/{keyword}"
        driver.get(keyword_url)

        time.sleep(3)

        product_info_list = []
        
        i = 1
        page_num = 1
        while len(product_info_list) < repeat:
            product_info = collect_product_details(driver, i, review_min, product_info_list)
            i = i + 1
            if product_info == 1:
                page_num = page_num + 1
                try:
                    next_page = driver.find_element(By.XPATH, f'//li[@title="{page_num}"]')
                    next_page.click()
                    time.sleep(1)
                    i = 1
                except:
                    print(f"{keyword} 상품 개수 부족")
                    return
                continue
            if product_info == -1:
                pyautogui.hotkey('win', 'ctrl', 'right')
                login_to_coupang(driver, email, password)
                driver.get(keyword_url)
                time.sleep(3)
                if page_num != 1:
                    next_page.click()
                    time.sleep(1)
                continue
            elif product_info == 0:
                continue
            product_info_list.append(product_info)

        #filtered_product_info_list = filter_product_info(product_info_list)
        html_code = generate_html_code(keyword, review_min, product_info_list)
        publish_post(keyword, html_code)
    except Exception as e:
        messagebox.showerror("오류", f"상품 정보 수집 중 오류 발생: {str(e)}")

def collect_product_details(driver, i, review_min, product_info_list):
    product_info = {}

    try:
        product_image = driver.find_element(By.XPATH, "(//img[@alt='product'])[" + str(i) + "]")
        product_image_url = product_image.get_attribute("src")
        product_info["상품 이미지 URL"] = product_image_url.strip()
    except:
        return 1

    actions = ActionChains(driver)
    actions.move_to_element(product_image).perform()
    time.sleep(0.5)

    driver.find_element(By.XPATH, "(//button[@class='ant-btn hover-btn btn-open-detail'])[" + str(i) + "]").click()

    all_tabs = driver.window_handles
    driver.switch_to.window(all_tabs[1])
    time.sleep(1)

    try:
        product_name_element = driver.find_element(By.CLASS_NAME, "prod-buy-header__title")
        product_info["상품명"] = product_name_element.text.strip()
    except:
        delete_cache(driver)
        driver.switch_to.window(all_tabs[0])
        return -1
    
    if filter_product_name(product_info_list, product_info["상품명"]) == 0:
#         # 현재 탭 닫기
        driver.close()

#         # 원래 탭으로 스위치
        driver.switch_to.window(all_tabs[0])
        return 0

    try:
        product_attr_elements = driver.find_elements(By.CLASS_NAME, "prod-attr-item")
        product_attrs = [attr.text for attr in product_attr_elements[:-1]]
        product_info["상품 정보"] = "⦁ "+"<br>⦁ ".join(product_attrs)
    except:
        product_info["상품 정보"] = ""

    if product_info["상품 정보"] == "⦁ ":
        product_info["상품 정보"] = "⦁ 상세페이지 참고"
        
    try:
        price_element = driver.find_element(By.CLASS_NAME, "total-price")
        product_info["가격"] = price_element.text.strip()
    except:
        product_info["가격"] = ""

    if (product_info["가격"] == ""):
#         # 현재 탭 닫기
        driver.close()

#         # 원래 탭으로 스위치
        driver.switch_to.window(all_tabs[0])
        return 0

    try:
        review_element = driver.find_element(By.XPATH, '//li[@name="review" and contains(text(), "상품평")]')
        review_element.click()
        time.sleep(1)
    except Exception as e:
        print("요소를 찾거나 클릭하는 중 오류 발생:", str(e))

    try:
        rating_element = driver.find_element(By.CSS_SELECTOR, '.js_reviewAverageTotalStarRating')
        product_info["상품평 평균 평점"] = rating_element.get_attribute("data-rating").strip()

        review_count_element = driver.find_element(By.CSS_SELECTOR, '.sdp-review__average__total-star__info-count')
        product_info["상품평 개수"] = review_count_element.text.strip()
    except:
        product_info["상품평 평균 평점"] = "0"
        product_info["상품평 개수"] = "0"

    # 현재 탭 닫기
    driver.close()

    # 원래 탭으로 스위치
    driver.switch_to.window(all_tabs[0])

    if (float(product_info["상품평 평균 평점"]) < 4.0 or int(product_info["상품평 개수"].replace(",", "")) < review_min):
        return 0

    # ActionChains를 사용하여 이미지 위에 마우스를 가져다 대기
    actions = ActionChains(driver)
    actions.move_to_element(product_image).perform()
    time.sleep(0.5)

    # "링크생성" 버튼을 클릭하여 새로운 탭으로 이동
    generate_link_button = driver.find_element(By.XPATH, "(//button[@class='ant-btn hover-btn btn-generate-link'])[" + str(i) + "]")
    generate_link_button.click()

    # 회원정보 확인 창 확인
    try:
        confirm_modal = WebDriverWait(driver, 1).until(EC.presence_of_element_located((By.CLASS_NAME, 'modal-title.large-title')))

        # 비밀번호 입력
        password_input = driver.find_element(By.ID, 'password')
        password_input.send_keys(password)

        # 확인 버튼 클릭
        confirm_button = driver.find_element(By.XPATH, "//button[@type='submit'][@class='ant-btn ant-btn-primary ant-btn-lg']") # 필요한 버튼을 정확한 XPath로 찾아서 클릭
        confirm_button.click()

    except:
        # 회원정보 확인 창이 없는 경우
        pass

    copy_url_button = driver.find_element(By.XPATH, "//button[@class='ant-btn lg shorten-url-controls-main']")
    copy_url_button.click()

    copied_url = pyperclip.paste()
    product_info["URL"] = copied_url.strip()

    driver.back()
    time.sleep(1)
    return product_info

def filter_product_name(product_info_list, product_name):
    for product in product_info_list:
        # 삭제 대상인 경우와 중복 상품인 경우 필터링
        if product_name == product["상품명"]:
            return 0
    return 1

# 글 발행 버튼 동작 함수
def publish_post(keyword, html_code):
    # WordPress에 게시
    try:
        # url, username, password
        client = Client('https://freeseren.com/xmlrpc.php', 'dhxh', 'Dhxhqht0308!')
        post = WordPressPost()

        post.title = f'{keyword} 추천 BEST 10 (가격, 후기, 별점, 상세정보)'  # 게시물 제목 설정
        post.content = html_code.replace('\n','')  # HTML 코드를 게시물 내용으로 설정
        post.excerpt = f"{keyword} 상품 중 인기 상품 BEST 10을 소개합니다. 어떤 제품을 구매할지 고민 중이신 분들께 도움이 되는 정보를 전해드릴게요. 소개해드리는 상품 리스트는 {keyword} 판매 순위와 리뷰를 토대로 직접 선정한 상품 10가지입니다."
        post.mime_type = "text/html"
        post.post_status = 'publish'  # 게시물 상태 설정

        # 태그와 카테고리 설정 (원하는대로 수정)
        post.terms_names = {
            'post_tag': [f'{keyword}', f'{keyword} 추천', f'{keyword} 후기', f'{keyword} 인기상품', f'{keyword} 순위', f'{keyword} 모음'],
            'category': ['Product', '식품']
        }

        # 게시물 게시
        post_id = client.call(posts.NewPost(post))
        print("성공", f"게시물이 성공적으로 게시되었습니다. (ID: {post_id})")

    except Exception as e:
        messagebox.showerror("오류", f"게시 중 오류 발생: {str(e)}")    

def generate_html_code(keyword, review_min, product_info_list):
    html_code = f"""        <p>이번 포스팅에서는 <strong>{keyword}</strong> 상품 중 <strong>인기 상품 BEST 10</strong>을 소개합니다.<br>
    어떤 제품을 구매할지 고민 중이신 분들께 도움이 되는 정보를 전해드릴게요.<br><br>
    소개해드리는 상품 리스트는 <strong>{keyword} 판매 순위와 리뷰</strong>를 토대로<strong> 직접 선정</strong>한 상품 10가지입니다.<br>
    <strong>리뷰 평점</strong> <strong>4.0 이상</strong>, <strong>리뷰 개수</strong> <strong>{review_min}개 이상</strong>인 제품만 선별하였습니다.<br><br>
    상품 리스트를 참고하여 꼼꼼히 살펴본 후 만족스러운 구매하시길 바랍니다.<br>
    각 상품의 후기나 가격 등은 변동될 수 있으니 직접 링크에 들어가서 다시 한 번 확인해보세요.</p>
    <h5>{keyword} 인기 상품 BEST 10</h5>
    <hr class="wp-block-separator has-alpha-channel-opacity is-style-wide">"""
    for i, product_info in enumerate(product_info_list):
        image_url = product_info["상품 이미지 URL"]
        product_name = product_info["상품명"]
        price = product_info["가격"]
        review = product_info["상품평 평균 평점"]
        review_count = product_info["상품평 개수"]
        product_detail_url = product_info["URL"]
        product_description = product_info["상품 정보"]
        
        # HTML 템플릿을 수정한 부분
        html_template = f"""
        <div class="wp-block-columns are-vertically-aligned-center is-layout-flex wp-container-14 wp-block-columns-is-layout-flex">
            <div class="wp-block-column is-vertically-aligned-center has-global-padding is-layout-constrained wp-block-column-is-layout-constrained" style="flex-basis:33.33%">
                <figure class="wp-block-image aligncenter size-large is-resized">
                    <a href="{product_detail_url}" target="_blank" rel="noreferrer noopener">
                        <img decoding="async" src="{image_url}" alt="" style="width:225px" width="225">
                    </a>
                </figure>
            </div>

            <div class="wp-block-column is-vertically-aligned-center is-layout-flow wp-block-column-is-layout-flow" style="flex-basis:66.66%">
                <div class="wp-block-group is-vertical is-content-justification-left is-layout-flex wp-container-8 wp-block-group-is-layout-flex">
                    <h6 class="wp-block-heading">
                        <span class="ez-toc-section" id="1_%EC%83%81%ED%92%88" ez-toc-data-id="#1_상품"></span>
                        <a href="{product_detail_url}" target="_blank" rel="noopener" title="">{i + 1}. {product_name}</a>
                        <span class="ez-toc-section-end"></span>
                    </h6>
                </div>

                <div class="wp-block-columns are-vertically-aligned-center is-layout-flex wp-container-12 wp-block-columns-is-layout-flex">
                    <div class="wp-block-column is-vertically-aligned-center is-layout-flow wp-block-column-is-layout-flow" style="flex-basis:60%">
                        <p>가격💲: {price}<br>리뷰⭐: {review}점 ({review_count}건)</p>
                    </div>

                    <div class="wp-block-column is-vertically-aligned-center has-global-padding is-layout-constrained wp-block-column-is-layout-constrained" style="flex-basis:40%">
                        <div class="wp-block-buttons alignwide is-content-justification-center is-layout-flex wp-container-10 wp-block-buttons-is-layout-flex">
                            <div class="wp-block-button has-custom-font-size has-small-font-size">
                                <a class="wp-block-button__link wp-element-button" href="{product_detail_url}" style="border-radius:15px" target="_blank" rel="noreferrer noopener">제품 상세보기</a>
                            </div>
                        </div>
                    </div>
                </div>

                <p>{product_description}</p>
            </div>
        </div>

        <hr class="wp-block-separator has-alpha-channel-opacity is-style-wide">
        """

        html_code += html_template
    html_code += f"""<p>지금까지 <strong>{keyword} 상품 BEST 10</strong>을 소개해드렸습니다.<br>다양한 구매 후기도 확인하시면서 마음에 드는 상품을 찾으시길 바랍니다.<br><br>
    찾으시는 상품이 없거나 더 많은 {keyword} 상품이 궁금하시다면 아래 검색창을 활용해주세요!</p>
    <iframe src="https://coupa.ng/cebmft" width="100%" height="44" frameborder="0" scrolling="no" referrerpolicy="unsafe-url"></iframe>
    <p>마지막으로, 제 블로그의 다른 포스팅도 확인해보시고 다음 포스팅에서 더 좋은 정보로 찾아뵙겠습니다.<br><br></p>
    <p class="has-text-align-center has-small-font-size">이 포스팅은 쿠팡 파트너스 활동의 일환으로, 이에 따른 일정액의 수수료를 제공받습니다.<br><br></p>"""
    return html_code

# GUI 생성 함수
def create_gui():
    # 메인 윈도우 생성
    window = tk.Tk()
    window.title("Coupang Product Info Collector")
    window.geometry("600x800")
    
    # 키워드 입력 레이블
    keyword_label = tk.Label(window, text="키워드 입력")
    keyword_label.place(x=10, y=20)

    # 키워드 입력 텍스트 상자
    keyword_entry = tk.Entry(window)
    keyword_entry.place(x=150, y=20)
    
    # 수집 개수 입력 레이블
    repeat_count = tk.Label(window, text="수집할 상품 개수 입력")
    repeat_count.place(x=10, y=50)

    # 수집 개수 입력 텍스트 상자
    repeat_entry = tk.Entry(window)
    repeat_entry.place(x=150, y=50)
    
    # 리뷰 개수 입력 레이블
    review_count = tk.Label(window, text="리뷰 최소 개수 입력")
    review_count.place(x=10, y=80)

    # 리뷰 개수 입력 텍스트 상자
    review_entry = tk.Entry(window)
    review_entry.place(x=150, y=80)
    
    # 구분선 출력 레이블
    sep_label = tk.Label(window, text="-----------------------------------------------------------------------------------------------------------------")
    sep_label.place(x=10, y=110)

    # 정보 수집 버튼
    def collect_info():
        keywords = keyword_entry.get().split(',')
        repeat = repeat_entry.get()
        review_min = review_entry.get()
        if not keywords:
            messagebox.showerror("오류", "키워드를 입력하세요.")
            return
        if not repeat:
            messagebox.showerror("오류", "수집할 상품의 개수를 입력하세요.")
            return
        if not review_min:
            messagebox.showerror("오류", "수집할 상품의 개수를 입력하세요.")
            return
        repeat = int(repeat)
        review_min = int(review_min)

        driver = initialize_driver()

        # 로그인
        email = "pwndud0421@naver.com"  # 여기에 쿠팡 파트너스 로그인 이메일을 입력하세요.
        password = "philia0421@"  # 여기에 쿠팡 파트너스 로그인 비밀번호를 입력하세요.
        login_to_coupang(driver, email, password)

        # 정보 수집 및 HTML 코드 생성
        for keyword in keywords:
            collect_product_info(driver, keyword.strip(), repeat, review_min, email, password)

        driver.quit()

    # 정보 수집 버튼
    collect_button = tk.Button(window, text="상품 정보 수집", command=collect_info)
    collect_button.place(x=480, y=80)

    # GUI 시작
    window.mainloop()

# GUI 실행
if __name__ == "__main__":
    create_gui()