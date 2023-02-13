#include <iostream>
#include <algorithm>
using namespace std;

int t, n;
int S[2][100005], D[2][100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t-- != 0)
    {
        fill(&D[0][0], &D[1][100005], 0);
        cin >> n;
        for (int i = 0; i < 2; i++)
            for (int j = 1; j <= n; j++)
                cin >> S[i][j];
        D[0][1] = S[0][1];
        D[1][1] = S[1][1];
        for (int i = 2; i <= n; i++)
        {
            D[0][i] = max(D[1][i - 1], D[1][i - 2]) + S[0][i];
            D[1][i] += max(D[0][i - 1], D[0][i - 2]) + S[1][i];
        }
        cout << max(D[0][n], D[1][n]) << '\n';
    }
}