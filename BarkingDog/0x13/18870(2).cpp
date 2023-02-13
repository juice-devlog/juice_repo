#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int a[1000005];
vector<int> uni;
int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        uni.push_back(a[i]);
    }
    sort(uni.begin(), uni.end());
    uni.erase(unique(uni.begin(), uni.end()), uni.end());
    for (int i = 0; i < n; i++)
        cout << lower_bound(uni.begin(), uni.end(), a[i]) - uni.begin() << ' ';
}
/* 백터 중복 원소 제거 */
// unique()는 연속된 중복 원소를 vector의 제일 뒷부분으로 쓰레기값으로 보내버린다. unique 실행 후 반환되는 값은 vector의 쓰레기값의 첫번째 위치가 되는데, 이를 활용해 erase()를 사용해 쓰레기값을 제거할 수 있다.