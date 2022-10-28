#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        stack<char> S;
        for(auto c : s){
            if(!S.empty() && c == S.top()) S.pop();
            else S.push(c);
        }
        if(S.empty()) ans++;
    }
    cout << ans;
}