#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

#define X first
#define Y second
int n, ans, cnt, shark_size = 2;
int board[22][22];
int dist[22][22];
int min_dist = 401, min_x = 21, min_y = 21;
bool edible;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
// vector<tuple<int, int, int>> edible;
queue<pair<int, int>> Q;

bool OOB(int x, int y){
    return x < 0 || y < 0 || x >= n || y >= n;
}

void bfs(){
    while(1){    
        edible = false;
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for (int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir], ny = cur.Y + dy[dir];
                if (OOB(nx, ny)) continue;
                if (board[nx][ny] > shark_size || dist[nx][ny] > -1) continue;
                Q.push({nx, ny});
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                if (board[nx][ny] < shark_size && board[nx][ny] > 0){             
                    edible = true;
                    if (min_dist > dist[nx][ny]){
                        min_x = nx;
                        min_y = ny;
                        min_dist = dist[nx][ny];
                    }
                    else if (min_dist == dist[nx][ny]){
                        if (min_x == nx){
                            if (min_y > ny){
                                min_y = ny;
                            }
                        }
                        else if (min_x > nx){
                            min_x = nx;
                            min_y = ny;
                        }
                    }    
                }
            }
        }
        if (edible){
            ans += dist[min_x][min_y];
            for (int i = 0; i < n; i++)
                fill(dist[i], dist[i]+n, -1);
            board[min_x][min_y] = 0;
            dist[min_x][min_y] = 0;
            Q.push({min_x, min_y});
            min_dist = 401;
            min_x = 21;
            min_y = 21;
            cnt++;
            if (cnt == shark_size){
                shark_size++;
                cnt = 0;
            }
        }
        else
            break;
        }
}
int main(void){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        fill(dist[i], dist[i]+n, -1);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> board[i][j];
            if (board[i][j] == 9){
                Q.push({i, j});
                board[i][j] = 0;
                dist[i][j] = 0;
            }
        }
    }
    bfs();
    cout << ans;
}