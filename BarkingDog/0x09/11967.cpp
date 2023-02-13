#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second
int n, m;
vector<pair<int, int>> V[102][102];
int board[102][102];
int vis[102][102];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while(m--){
        int x, y, a, b;
        V[x][y].push_back({a, b});
    }

    queue<pair<int, int>> Q;
    Q.push({1, 1});
    vis[1][1] = 2;
    int cnt = 1;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        int x = cur.X, y = cur.Y;
        for (auto i : V[x][y]){
            int nx = i.X, ny = i.Y;
            if(!vis[nx][ny]){
                for (int dir = 0; dir < 4; dir++){
                    int tx = nx + dx[dir], ty = ny + dy[dir];
                    if (vis[tx][ty] == 2){
                        Q.push({tx, ty});
                        break;
                    }
                }
                vis[nx][ny] = 1;
                cnt++;
            }
        }
        for (int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir], ny = y + dy[dir];
            if (vis[nx][ny] == 1){
                vis[nx][ny] == 2;
                Q.push({nx, ny});
            }
        }
    }
    cout << cnt;
}