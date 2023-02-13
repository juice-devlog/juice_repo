#include <bits/stdc++.h>
using namespace std;

int arr[21];
int n, s;
int cnt = 0;
void func(int idx, int sum){
    if(idx == n){
        if(sum == s) cnt++;
        return;
    }
    func(idx+1, sum);
    func(idx+1, sum+arr[idx]);
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> arr[i];
    func(0, 0);
    if(s == 0) cnt--;
    cout << cnt;
}