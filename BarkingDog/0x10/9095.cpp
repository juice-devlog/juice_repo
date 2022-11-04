#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int D[12];
    int t, n;
    D[1] = 1; D[2] = 2; D[3] = 4;
    cin >> t;
    while(t-- != 0){
        cin >> n;
        for(int i = 4; i <= n; i++)
            D[i] = D[i-1] + D[i-2] + D[i-3];
        cout << D[n] << '\n';
    }
}