#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, end = 0, cnt = 0;
    pair <int, int> s[100005];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i].second >> s[i].first;
    sort(s, s+n);
    for(int i = 0; i < n; i++){
        if(end > s[i].second) continue;
        end = s[i].first;
        cnt++;
    }
    cout << cnt;
}