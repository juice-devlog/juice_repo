#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int D[41][2];
    int t, n;
    D[0][0] = 1; D[0][1] = 0;
    D[1][0] = 0; D[1][1] = 1;
    for(int i = 2; i <= 40; i++){
        D[i][0] = D[i-2][0] + D[i-1][0];
        D[i][1] = D[i-2][1] + D[i-1][1];
    }
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        cout << D[n][0] << ' ' << D[n][1] << '\n';
    }
}