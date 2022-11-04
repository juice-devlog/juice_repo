#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r, g, b;
    int D[1001][3];
    cin >> n;
    cin >> D[1][0] >> D[1][1] >> D[1][2];
    for(int i = 2; i <= n; i++){
        cin >> r >> g >> b;
        D[i][0] = min(D[i-1][1], D[i-1][2]) + r;
        D[i][1] = min(D[i-1][0], D[i-1][2]) + g;
        D[i][2] = min(D[i-1][0], D[i-1][1]) + b;
    }
    cout << *min_element(D[n], D[n]+3);
}