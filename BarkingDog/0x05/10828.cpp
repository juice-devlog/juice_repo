#include <bits/stdc++.h>
using namespace std;

const int MX = 10005;
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
    if (pos > 0)
        return (dat[pos - 1]);
    else
        return (-1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, val;
    cin >> n;
    string    command;
    for (int i = 0; i < n; i++){
        cin >> command;
        if (command == "push"){
            cin >> val;
            push(val);
        }
        else if (command == "pop"){
            if (pos == 0)
                cout << -1 << '\n';
            else{
                cout << top() << '\n';
                pop();
            }
        }
        else if (command == "size")
            cout << pos << '\n';
        else if (command == "empty"){
            if (pos == 0)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else
            cout << top() << '\n';
    }
}