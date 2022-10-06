#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string maze[1002];
int fire[1002][1002];
int route[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r, c;
    string info;
    queue<pair<int, int> > Q;
    pair<int, int> J;
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        cin >> info;
        maze[i] = info;
        for(int j = 0; j < c; j++){
            if(maze[i][j] == 'J') J = make_pair(i, j);
            if(maze[i][j] == 'F'){
                Q.push({i, j});
                fire[i][j] = 0;
            }
            else fire[i][j] = -1;
            route[i][j] = -1;
        }
    }
    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(fire[nx][ny] != -1 || maze[nx][ny] == '#') continue;
            Q.push({nx, ny});
            fire[nx][ny] = fire[cur.X][cur.Y] + 1;
        }
    }
    Q.push({J.X, J.Y});
    route[J.X][J.Y] = 0;
    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(route[nx][ny] != -1 || maze[nx][ny] != '.' || (fire[nx][ny] <= route[cur.X][cur.Y] + 1 && fire[nx][ny] != -1)) continue;
            Q.push({nx, ny});
            route[nx][ny] = route[cur.X][cur.Y] + 1;
        }
    }
    int ans = 1000002;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if((i == 0 || i == (r - 1) || j == 0 || j == (c - 1)) && route[i][j] != -1)
                ans = min(ans, route[i][j]);
        }
    }
    if(ans == 1000002) cout << "IMPOSSIBLE";
    else cout << ans + 1;
}