// http://boj.kr/ece8236c02cf46aba9933f28e358b51c
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  for(char a = 'a'; a <= 'z'; a++){
    int cnt = 0;
    for(auto c : s)
      if(a == c) cnt++;
    cout << cnt << ' ';
  }
}

// http://boj.kr/d7178d89538a42ababf4455443e60fe2
#include <bits/stdc++.h>
using namespace std;

int freq[26]; // 전역에 선언했기 때문에 자동으로 0으로 채워진다
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  for(auto c : s)
    freq[c-'a']++;
  for(int i = 0; i < 26; i++)
    cout << freq[i] << ' ';
}