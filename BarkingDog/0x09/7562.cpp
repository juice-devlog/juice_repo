#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int chess[302][302];
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        fill(chess[0], &chess[301][302], 0);
        int I, start_x, start_y, dest_x, dest_y;
        cin >> I >> start_x >> start_y >> dest_x >> dest_y;
        queue<pair<int, int> > Q;
        pair<int, int> cur = {-1, -1};
        Q.push({start_x, start_y});
        chess[start_x][start_y] = 1;
        while(!Q.empty()){
            cur = Q.front(); Q.pop();
            if(cur.X == dest_x && cur.Y == dest_y) break;
            for(int dir = 0; dir < 8; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= I || ny < 0 || ny >= I) continue;
                if(chess[nx][ny] > 0) continue;
                chess[nx][ny] = chess[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }
        cout << chess[cur.X][cur.Y] - 1 << '\n';
    }
}