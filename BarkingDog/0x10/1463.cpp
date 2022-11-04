#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, i = 2, cnt = 0;
    cin >> n;
    int D[n+1];
    D[1] = 0;
    for(int i = 2; i <= n; i++){
        D[i] = D[i-1] + 1;
        if(i % 2 == 0) D[i] = min(D[i], D[i/2] + 1);
        if(i % 3 == 0) D[i] = min(D[i], D[i/3] + 1);
    }
    cout << D[n];
}
/*
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1: 1 (0)
2: 2 1 (1)
3: 3 1 (1)
4: 4 2 1 or 4 3 1 (2)
5: 5 4 2 1 or 5 4 3 1 (3)
6: 6 3 1 or 6 2 1 (2)
7: 7 6 3 1 or 7 6 2 1 (3)
8: 8 4 2 1
16: 16 15 5 4 2 1 or 16 8 4 2 1
*/