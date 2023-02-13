#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int K, W, H;
int board[205][205];
int vis[205][205];
int cnt[205][205];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dx_horse[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy_horse[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

void BFS(int x, int y){
    queue<pair<int, int> > Q;
    vis[x][y] = 1;
    Q.push({x, y});
    int j = 0;
    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(board[nx][ny] == 1) continue;
            if(vis[nx][ny] == 0){
                vis[nx][ny] = 1;
                Q.push({nx, ny});
                cnt[nx][ny] = cnt[cur.X][cur.Y] + 1;
            }
        }
        if(j < K){
            for(int i = 0; i < 8; i++){
                int nx = cur.X + dx_horse[i];
                int ny = cur.Y + dy_horse[i];
                if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if(board[nx][ny] == 1) continue;
                if(vis[nx][ny] == 0){
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                    cnt[nx][ny] = cnt[cur.X][cur.Y] + 1;
                }
            }
            j++;
        }
    }

}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> K >> W >> H;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> board[i][j];
        }
    }
    BFS(0, 0);
    if(vis[H-1][W-1] == 0) cout << -1;
    else cout << cnt[H-1][W-1];
}