#include <bits/stdc++.h>
using namespace std;

const int MX = 10005;
int dat[2*MX + 1];
int head = MX, tail = MX;

void push_front(int val)
{
    dat[--head] = val;
}

void push_back(int val)
{
    dat[tail++] = val;
}

void pop_front()
{
    head++;
}

void pop_back()
{
    tail--;
}

int front()
{
    return(dat[head]);
}

int back()
{
    return(dat[tail - 1]);
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
        if (command == "push_front"){
            cin >> val;
            push_front(val);
        }
        else if (command == "push_back"){
            cin >> val;
            push_back(val);
        }
        else if (command == "pop_front"){
            if (head == tail)
                cout << -1 << '\n';
            else{
                cout << front() << '\n';
                pop_front();
            }
        }
        else if (command == "pop_back"){
            if (head == tail)
                cout << -1 << '\n';
            else{
                cout << back() << '\n';
                pop_back();
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
        else if (command == "front"){
            if (head == tail)
                cout << -1 << '\n';
            else
                cout << front() << '\n';
        }
        else{
            if (head == tail)
                cout << -1 << '\n';
            else
                cout << back() << '\n';
        }
    }
}