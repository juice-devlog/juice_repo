#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long D[10005][3];
    int glass[10005];
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> glass[i];
    D[1][0] = 0;
    D[1][1] = glass[1];
    D[1][2] = glass[1];
    D[2][0] = D[1][1];
    D[2][1] = D[1][0] + glass[2];
    D[2][2] = D[1][1] + glass[2];
    for (int i = 3; i <= n; i++)
    {
        D[i][0] = max(D[i-1][0], max(D[i - 1][1], D[i - 1][2]));
        D[i][1] = D[i - 1][0] + glass[i];
        D[i][2] = D[i - 1][1] + glass[i];
    }
    cout << max(D[n][0], max(D[n][1], D[n][2]));
}