#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N[100001], D[100001];
    int n, m, i, j;
    cin >> n >> m;
    for(int k = 1; k <= n; k++){
        cin >> N[k];
        D[k] = D[k-1] + N[k];
    }
    while(m--){
        cin >> i >> j;
        cout << D[j] - D[i-1] << '\n';
    }
}