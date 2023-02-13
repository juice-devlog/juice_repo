#include <bits/stdc++.h>
using namespace std;

int T[20], P[20], D[20];
// D[i]는 i일부터 시작했을 때 얻을 수 있는 최대값

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> T[i] >> P[i];
    for (int i = n; i >= 1; i--) // n일부터 가능한지 생각
    {
        if(T[i] + i - 1 <= n)
            D[i] = max(D[i+T[i]] + P[i], D[i+1]);
        else
            D[i] = D[i + 1];
    }
    cout << D[1];
}