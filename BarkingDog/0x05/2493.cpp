#include <bits/stdc++.h>
using namespace std;

const int MX = 500005;
int dat[MX];
int pos = 0;

void push(int val)
{
    dat[pos++] = val;
}

void pop()
{
    pos--;
}

int top()
{
    return (dat[pos - 1]);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, height, idx = 0;
    cin >> n;
    int arr[n] = { 0, };
    for (int i = 0; i < n; i++){
        cin >> height;
        push(height);
    }
    while (pos > 0){
        int cur, count = 0;
        cur = top();
        pop();
        if (cur < top()){
            arr[idx] = pos;
            idx++;
        }
        else{
            while (cur > top() && pos > 0){
                pop();
                count++;
            }
            while (count >= 0){
                arr[idx] = pos;
                idx++;
                count--;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
        cout << arr[i] << ' ';
}