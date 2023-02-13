#include <iostream>
#include <algorithm>
using namespace std;

long D[1000005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    cin >> t;
    D[1] = 1;
    D[2] = 2;
    D[3] = 4;
    for (int i = 4; i <= 1000000; i++)
        D[i] = (((D[i - 1] % 1000000009 + D[i - 2] % 1000000009) % 1000000009) + D[i - 3] % 1000000009) % 1000000009;
    while (t-- != 0)
    {
        cin >> n;
        cout << D[n] % 1000000009 << '\n';
    }
}