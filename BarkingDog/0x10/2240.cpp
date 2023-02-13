#include <iostream>
#include <algorithm>
using namespace std;

int T, W;
int a[1005], cnt[1005], D[1005];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T >> W;
    for (int i = 1; i <= T; i++)
        cin >> a[i];
    int idx = 1;
    for(int i = 1; i <= T; ){
        int cur = a[i], c = 0;
        while(a[i] == cur){
            c++;
            i++;
        }
        cnt[idx] = c;
        idx++;
    }
    D[1] = cnt[1];
    for (int i = 2; i < idx; i++){
        D[i] = D[i - 1] + cnt[i];
        cout << D[i] << ' ';
    }
} //2112211