#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, N;
    long D[105];
    D[1] = 1;
    D[2] = 1;
    D[3] = 1;
    D[4] = 2;
    D[5] = 2;
    cin >> T;
    while(T--){
        cin >> N;
        for (int i = 6; i <= N; i++)
            D[i] = D[i - 5] + D[i - 1];
        cout << D[N] << '\n';
    }
}