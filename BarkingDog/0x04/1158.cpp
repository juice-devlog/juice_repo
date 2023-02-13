#include <bits/stdc++.h>
using namespace std;

int const MX = 5005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

void    erase(int addr)
{
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1)
        pre[nxt[addr]] = pre[addr];
}

void    insert(int addr, int val)
{
    dat[unused] = val;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        insert(i, i + 1);
    nxt[n] = nxt[0];
    int loc = 0;
    int idx = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            loc = nxt[loc];
        }
        arr[idx] = dat[loc];
        idx++;
        erase(loc);
        nxt[n] = nxt[0];
        loc = pre[loc];
    }
    cout << '<';
    for (int i = 0; i < n - 1; i++) cout << arr[i] << ", ";
    cout << arr[n - 1] << '>';
}