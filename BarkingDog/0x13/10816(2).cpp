#include <bits/stdc++.h>
using namespace std;

int a[500005];
int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int m;
    cin >> m;
    while (m--)
    {
        int num;
        cin >> num;
        cout << upper_bound(a, a+n, num) - lower_bound(a, a+n, num) << ' ';
    }
}
/* upper_bound(arr.begin(), arr.end(), key), lower_bound(arr.begin(), arr.end(), key) */
// 이진 탐색으로 원소를 탐색(O(logN))
// 탐색을 진행할 배열 혹은 벡터는 오름차순 정렬되어 있어야 한다.
// upper_bound: 찾으려는 key 값을 초과하는 숫자가 배열 몇 번째에서 처음 등장하는지 찾기 위해 사용한다.
// lower_bound: 찾으려는 key 값과 같거나 큰 숫자가 배열 몇 번째에서 처음 등장하는지 찾기 위해 사용한다.
// 벡터의 경우 v.begin()을 빼 주어야 한다.