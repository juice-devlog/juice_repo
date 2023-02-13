#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int D[501][501];
    int n, num;
    cin >> n >> D[1][1];
    int mx = D[1][1];
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> num;
            if(j == 1) D[i][j] = D[i-1][j] + num;
            if(j == i) D[i][j] = D[i-1][j-1] + num;
            D[i][j] = max(D[i-1][j-1], D[i-1][j]) + num;
            mx = max(mx, D[i][j]);
        }
    }
    cout << mx; // *max_element(D[n]+1, D[n]+n+1)
}