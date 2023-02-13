#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m[13];
    m[0] = 0;
    for(int i = 1; i < 13; i++){
        int date = 31;
        if(i == 4 || i == 6 || i == 9 || i == 11) date = 30;
        if(i == 2) date = 28;
        m[i] = m[i-1] + date;
        cout << m[i] << ' ';
    }
    int n, month, day;
    pair <int, int> s[100005];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> month >> day;
        //cout << month << day;
        s[i].first = m[month-1] + day;
        cin >> month >> day;
        //cout << month << day;
        s[i].second = m[month-1] + day;
    }
    sort(s, s+n);
    /*for(int i = 0; i < n; i++){
        cout << s[i].first << ' ' << s[i].second << '\n';
    }*/
    int max_end, max_idx, cnt = 0;
    for(int i = 0; i < n; i++){
        while(s[idx].first < end){
            int idx = i;
            if(s[idx].second > max_end){
                max_end = s[idx].second;
                max_idx = i;
            }
            i++;
        }

    }
    cout << cnt;
}
/*앞에 끝나는 친구랑 시작값이 겹치되 뒤에 끝나는 값은 가장 큰 꽃을 골라야 한다*/