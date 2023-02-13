#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string maze[102];
int route[102][102];
bool vis[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    string info;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> info;
        maze[i] = info;
    }
    queue<pair<int, int> > Q;
    Q.push({0, 0});
    route[0][0] = 1;
    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] || maze[nx][ny] == '0') continue;
            vis[nx][ny] = 1;
            route[nx][ny] = route[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    int up = route[n - 2][m - 1];
    int left = route[n - 1][m - 2];
    if((up > 0 && left > 0 && up <= left) || left == 0)
        cout << up + 1;
    else if((up > 0 && left > 0 && up > left) || up == 0)
        cout << left + 1;
}