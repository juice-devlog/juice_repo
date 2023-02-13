#include <iostream>
#include <algorithm>
using namespace std;

int n;
int D[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> D[i];
    for (int i = 2; i <= n; i++)
        for (int j = 0; j <= i ; j++)
            D[i] = max(D[i], D[i - j] + D[j]);
    cout << D[n];
}