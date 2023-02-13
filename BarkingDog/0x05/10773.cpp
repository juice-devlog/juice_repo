#include <bits/stdc++.h>
using namespace std;

const int MX = 100005;//상수, 변경 불가능
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
    return(dat[pos - 1]);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); //입출력으로 인한 시간초과 막기
    int k, val, sum = 0;
    cin >> k;//k개 만큼의 val 받기
    for (int i = 0; i < k; i++){
        cin >> val;
        if (val == 0)
            pop();
        else
            push(val);
    }
    while (pos > 0){
        sum += top();
        pop();
    }
    cout << sum;
}