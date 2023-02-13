#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long D[95][2];
    int n;
    cin >> n;
    D[1][0] = 0;
    D[1][1] = 1;
    for (int i = 2; i <= n; i++){
        D[i][0] = D[i - 1][0] + D[i - 1][1];
        D[i][1] = D[i - 1][0];
    }
    cout << D[n][0] + D[n][1];
}

D[i][0] = D[i - 1][0] + D[i - 1][1] = D[i - 1];
D[i - 1][0] = D[i - 2][0] + D[i - 2][1] = D[i-2] = D[i][1];
D[i] = D[i][0] + D[i][1] = D[i-1] + D[i-2];