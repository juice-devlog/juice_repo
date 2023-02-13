#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int K, W, H;
int board[205][205];
bool vis[205][205][32];
int cnt[205][205];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dx_h[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy_h[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int BFS(int x, int y){
    queue<pair<pair<int, int>, pair<int, int>> > Q;
    for(int i = 0; i <= K; i++){
        vis[x][y][i] = 1;
    }
    Q.push({{x, y}, {0, 0}});
    while(!Q.empty()){
        pair<pair<int, int>, pair<int, int> > cur = Q.front(); Q.pop();
        if(cur.X.X == H-1 && cur.X.Y == W-1){
            return cur.Y.X;
        }
        for(int i = 0; i < 4; i++){
            int nx = cur.X.X + dx[i];
            int ny = cur.X.Y + dy[i];
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(board[nx][ny] == 1) continue;
            if(vis[nx][ny][cur.Y.Y] == 0){
                vis[nx][ny][cur.Y.Y] = 1;
                Q.push({{nx, ny}, {cur.Y.X+1, cur.Y.Y}});
            }
        }
        if(cur.Y.Y < K){
            for(int i = 0; i < 8; i++){
                int nx = cur.X.X + dx_h[i];
                int ny = cur.X.Y + dy_h[i];
                if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if(board[nx][ny] == 1) continue;
                if(vis[nx][ny][cur.Y.Y+1] == 0){
                    vis[nx][ny][cur.Y.Y+1] = 1;
                    Q.push({{nx, ny}, {cur.Y.X+1, cur.Y.Y+1}});
                }
            }
        }
    }
    return -1;
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
    cout << BFS(0, 0);
}