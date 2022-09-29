#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
char    dat[MX];
int pre[MX], nxt[MX];
int unused = 1;

void    erase(int addr)
{
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1)
        pre[nxt[addr]] = pre[addr];
}

void    insert(int addr, char c)
{
    dat[unused] = c;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void    traverse()
{
    int cur = 0;
    cur = nxt[cur];
    while (cur != -1){
        cout << dat[cur];
        cur = nxt[cur];
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num;
    cin >> num;
    string s;
    for(int i = 0; i < num; i++){
        fill(pre, pre + MX, -1);
        fill(nxt, nxt + MX, -1);
        cin >> s;
        int cursor = 0;
        for (int i = 0; s[i]; i++){
            if (s[i] == '-' && pre[cursor] != -1){
                erase(cursor);
                cursor = pre[cursor];
            }
            else if (s[i] == '<' && pre[cursor] != -1)
                cursor = pre[cursor];
            else if (s[i] == '>' && nxt[cursor] != -1)
                cursor = nxt[cursor];
            else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')){
                insert(cursor, s[i]);
                cursor = nxt[cursor];
            }
            else
                continue;
        }
        traverse();
    }
}