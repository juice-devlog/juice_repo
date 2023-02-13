#include <iostream>
using namespace std;

void    traverse(){
    int cur = nxt[0];
    while (cur != -1){
        cout << dat[cur] << ' ';
        cur = nxt[cur];
    }
    cout << "\n\n";
}

int main(void){
    const int MX = 1000005; // 상수 변수는 초기화할 때 이외에 값을 변경할 수 없다
    int unsused = -1;

    fill(pre, pre + MX, -1); 
    fill(nxt, nxt + MX, -1);
    // fill 함수는 어떤 연속성을 띈 자료구조의 시작점부터 연속된 범위를 어떤 값이나 객체로 모두 지정하고 싶을 때 사용 -- fill (ForwardIterator first, ForwardIterator last, const T& val); 헤더파일은 <algorithm>, first는 채우고자 하는 자료구조의 시작위치, last는 채우고자 하는 자료구조의 끝 위치(last는 포함 x), val은 first부터 last 전까지 채우려고 하는 값
}