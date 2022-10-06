#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string color[102];
char color_x[102][102];
int vis[102][102];
int vis_x[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4]= {0, 1, 0, -1};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> color[i];
        for(int j = 0; j < n; j++){
            if(color[i][j] == 'G') color_x[i][j] = 'R';
            else color_x[i][j] = color[i][j];
        }
    }
    int cnt = 0, cnt_x = 0;
    queue<pair<int, int> > Q;
    queue<pair<int, int> > Q_x;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vis[i][j] == 0){
                //cout << "vis: " << i << ' ' << j << ' ';
                Q.push({i, j});
                vis[i][j] = 1;
                cnt++;
                //cout << '\n';
                /*for(int k = 0; k < n; k++){
                    for(int p = 0; p < n; p++)
                        cout << vis[k][p] << ' ';
                    cout << '\n';
                }*/
            }
            if(vis_x[i][j] == 0){
                //cout << "vis_x: " << i << ' ' << j << ' ';
                Q_x.push({i, j});
                vis_x[i][j] = 1;
                cnt_x++;
                //cout << '\n';
                /*for(int k = 0; k < n; k++){
                    for(int p = 0; p < n; p++)
                        cout << vis_x[k][p] << ' ';
                    cout << '\n';
                }*/
            }
            while(!Q.empty()){
                pair<int, int> cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;                    
                    if(vis[nx][ny] != 0 || color[nx][ny] != color[cur.X][cur.Y]) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            while(!Q_x.empty()){
                pair<int, int> cur = Q_x.front(); Q_x.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;                    
                    if(vis_x[nx][ny] != 0 || color_x[nx][ny] != color_x[cur.X][cur.Y]) continue;
                    vis_x[nx][ny] = 1;
                    Q_x.push({nx, ny});
                }
            }
        }
    }
    cout << cnt << ' ' << cnt_x;
}