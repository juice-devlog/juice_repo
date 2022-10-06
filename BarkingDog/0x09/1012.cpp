#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, m, n, k, x, y;
    cin >> t;
    for(int i = 0; i < t; i++){
        int field[52][52] = { 0, };
        int vis[52][52] = { 0, };
        cin >> m >> n >> k;
        queue<pair<int, int> > S;
        queue<pair<int, int> > Q;
        for(int j = 0; j < k; j++){
            cin >> x >> y;
            field[x][y] = 1;
            S.push({x, y});
        }
        int cnt = 0;
        while(!S.empty()){
        pair<int, int> start = S.front(); S.pop();
        if(vis[start.X][start.Y] == 1) continue;
        else{
            Q.push({start.X, start.Y});
            vis[start.X][start.Y] = 1;
            cnt++;
        }
            while(!Q.empty()){
                pair<int, int> cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if(vis[nx][ny] != 0 || field[nx][ny] != 1) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
        cout << cnt << '\n';
    }
}