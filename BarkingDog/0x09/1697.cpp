#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int loc[200005];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    if(n == k){
        cout << 0;
        return 0;
    }
    queue<int> Q;
    Q.push(n);
    loc[n] = 0;
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        int front = cur + 1;
        int back = cur - 1;
        int jump = cur * 2;
        if(front < k + 1 && loc[front] == 0){
            loc[front] = loc[cur] + 1;
            Q.push(front);
        }
        if(back >= 0 && loc[back] == 0){
            loc[back] = loc[cur] + 1;
            Q.push(back);
        }
        if(jump < 2 * k && loc[jump] == 0){
            loc[jump] = loc[cur] + 1;
            Q.push(jump);
        }
        if(front == k){
            cout << loc[front];
            break;
        }
        if(back == k){
            cout << loc[back];
            break;
        }
        if(jump == k){
            cout << loc[jump];
            break;
        }
    }
}