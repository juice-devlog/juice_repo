#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int arr[100005];
    int D[100005];
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        D[i] = arr[i];
    }
    D[0] = 0;
    for (int i = 1; i <= n; i++)
        D[i] = max(D[i], D[i - 1] + arr[i]);
    cout << *max_element(D+1, D+n+1);
}