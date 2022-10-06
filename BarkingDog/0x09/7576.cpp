#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int box[1002][1002];
int day[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> m >> n;
    queue<pair<int, int> > Q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            day[i][j] = -1;
            cin >> box[i][j];
            if(box[i][j] == 1){
                Q.push({i, j});
                day[i][j] = 0;
            }
        }
    }
    pair<int, int> cur;
    while(!Q.empty()){
        cur = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(day[nx][ny] != -1 || box[nx][ny] != 0) continue;
            day[nx][ny] = day[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    int flag = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            if(day[i][j] == -1 && box[i][j] == 0) flag = -1;
        if(flag == -1) break;
    }
    if(flag == -1)
        cout << -1;
    else
        cout << day[cur.X][cur.Y];
}