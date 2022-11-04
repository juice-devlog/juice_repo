#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int D[301][3];
    int n, p, flag = 0;
    cin >> n;
    cin >> D[1][1];
    D[1][2] = 0;
    cin >> D[2][1];
    D[2][2] = D[1][1] + D[2][1];
    for(int i = 3; i <= n; i++){
        cin >> p;
        D[i][1] = max(D[i-2][1], D[i-2][2]) + p;
        D[i][2] = D[i-1][1] + p;
    }
    cout << max(D[n][1], D[n][2]);
}