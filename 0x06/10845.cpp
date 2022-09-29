#include <bits/stdc++.h>
using namespace std;

const int   MX = 10005;
int dat[MX];
int tail = 0, head = 0;

void    push(int val)
{
    dat[tail++] = val;
}

void    pop()
{
    head++;
}

int front()
{
    return (dat[head]);
}

int back()
{
    return (dat[tail - 1]);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++){
        string command;
        cin >> command;
        if (command == "push"){
            cin >> val;
            push(val);
        }
        else if (command == "pop"){
            if (head == tail)
                cout << -1 << '\n';
            else{
                cout << front() << '\n';
                pop();
            }
        }
        else if (command == "size")
            cout << tail - head << '\n';
        else if (command == "empty"){
            if (head == tail)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (command == "front")
            cout << front() << '\n';
        else
            cout << back() << '\n';
    }
}