#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
char board[1002][1002];
int vis[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M, P;
int cnt[10];
queue<pair<int, int>> S[10];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> P;
    for (int i = 1; i <= P; i++)
        cin >> cnt[i];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++){
            cin >> board[i][j];
            if(board[i][j] >= '1' && board[i][j] <= '9')
                S[board[i][j] - '0'].push({i, j});
        }
    }
    bool round = true;
    while (round)
    {
        round = false;
        int p = 1;
        while (p <= P)
        {
            queue<pair<int, int>> Q;
            while (!S[p].empty())
            {
                fill(&vis[0][0], &vis[1001][1002], -1);
                pair<int, int> k = S[p].front(); S[p].pop();
                Q.push({k.X, k.Y});
                vis[k.X][k.Y] = 0;

                while (!Q.empty())
                {
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                            continue;
                        if (vis[nx][ny] != -1 || board[nx][ny] == '#') continue;
                        if (board[nx][ny] != '.' && board[nx][ny] != p + '0') continue;
                        vis[nx][ny] = vis[cur.X][cur.Y] + 1;
                        if (vis[nx][ny] == cnt[p]){
                            S[p].push({nx, ny});
                            board[nx][ny] = p + '0';
                            round = true;
                        }
                        Q.push({nx, ny});
                    }
                }
                /*for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                        cout << vis[i][j] << ' ';
                    cout << '\n';
                }
                cout << '\n';*/
            }
            p++;
        }
    }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
                cout << board[i][j] << ' ';
            cout << '\n';
        }
}