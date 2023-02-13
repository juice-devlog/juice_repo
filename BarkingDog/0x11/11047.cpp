#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, cnt = 0;
    int arr[11];
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = n-1; i >= 0; i--){
        cnt += k / arr[i];
        k %= arr[i];
    }
    cout << cnt;
}