#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<pair<int, char> > S;
    string s;
    cin >> s;
    int stick = 0;
    for(int i = 0; s[i]; i++){
        if(s[i] == '(') S.push({i, s[i]});
        else{
            pair<int, int> cur = S.top();
            if(cur.second == '(') S.pop();
            if(i - cur.first > 1)
                stick = stick + S.size();
        }
    }
    cout << stick;
}
/* 쇠막대기 개수: 괄호가 하나 만들어질 때 ++
근데 괄호가 () 이거면 안됨
자기짝 맞은 애를 찾으면 +1*/