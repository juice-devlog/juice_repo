#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long D[105][12];
    cin >> n;
    D[1][0] = 0;
    for (int i = 1; i < 10; i++)
        D[1][i] = 1;
    for (int i = 2; i <= n; i++)
    {
        D[i][0] = D[i - 1][1] % 1000000000;
        D[i][9] = D[i - 1][8] % 1000000000;
        for (int j = 1; j < 9; j++)
            D[i][j] = (D[i-1][j-1] + D[i-1][j+1]) % 1000000000;
    }
    int ans = 0;
    for (int i = 0; i < 10; i++)
        ans = (ans + D[n][i]) % 1000000000;
    cout << ans;
}

/*9의 개수 = 직전 n의 8의 개수
8의 개수 = 직전 n의 7의 개수 + 9의 개수
7의 개수 = 직전 n의 6의 개수 + 8의 개수
...
1의 개수 = 직전 n의 0의 개수 + 2의 개수
0의 개수 = 직전 n의 1의 개수*/