#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
char building[1002][1002];
int fire[1002][1002];
int sang[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int w, h;
        cin >> w >> h;
        queue<pair<int, int> > Qf,Qs;
        for(int j = 0; j < h; j++){
            for(int k = 0; k < w; k++){
                cin >> building[j][k];
                if(building[j][k] == '*'){
                    fire[j][k] = 0;
                    Qf.push({j, k});
                }
                else if(building[j][k] == '@'){
                    sang[j][k] = 0;
                    Qs.push({j, k});
                }
                else{
                    fire[j][k] = -1;
                    sang[j][k] = -1;
                }
            }
        }
        while(!Qf.empty()){
            pair<int, int> cur = Qf.front(); Qf.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(fire[nx][ny] != -1 || building[nx][ny] == '#') continue;
                fire[nx][ny] = fire[cur.X][cur.Y] + 1;
                Qf.push({nx, ny});
            }
        }
        bool escape = false;
        while(!Qs.empty()){
            pair<int, int> cur = Qs.front(); Qs.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(sang[cur.X][cur.Y] > fire[nx][ny]) continue;
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) {
                    cout << sang[cur.X][cur.Y] + 1 << '\n';
                    escape = true;
                    break;
                }
                if(sang[nx][ny] != -1 || building[nx][ny] != '.') continue;
                sang[nx][ny] = sang[cur.X][cur.Y] + 1;
                Qs.push({nx, ny});
            }
        }
        if(!escape) cout << "IMPOSSIBLE" << '\n';
    }
}