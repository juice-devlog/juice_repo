#include <bits/stdc++.h>
using namespace std;

const int MX = 100005;
int dat[MX];
char arr[MX];
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
    if (pos == 0)
        return (-1);
    else
        return (dat[pos - 1]);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, num, fail, idx = 0, val = 1;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> num;
        if (top() != num){
            while(val <= num && val <= n){
                push(val);
                arr[idx] = '+';
                val++;
                idx++;
            }
        }
        if (top() == num){
            pop();
            arr[idx] = '-';
            idx++;
        }
        else{
            fail = 1;
            break;
        }
    }
    if (fail == 1) cout << "NO";
    else{
    for (int i = 0; i < idx; i++) cout << arr[i] << '\n';
    }
}