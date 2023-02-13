#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int D[1001];
    cin >> n;
    D[1] = 1;
    D[2] = 2;
    for(int i = 3; i <= n; i++)
        D[i] = (D[i-1] + D[i-2]) % 10007;
    cout << D[n];
}