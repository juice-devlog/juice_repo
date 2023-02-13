#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define X first
#define Y second
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
char board[105][105];
bool vis[105][105];
string key;

int T, h, w;

bool OOB(int x, int y){
    return x < 0 || y < 0 || x > h+1 || y > w+1;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--){
        queue<pair<int, int>> Q;
        queue<pair<int, int>> D[26];
        cin >> h >> w;
        for (int i = 0; i < h+2; i++){
            fill(vis[i], vis[i]+w+2, 0);
            fill(board[i], board[i]+w+2, 0);
        } 
        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= w; j++)
                cin >> board[i][j];
        cin >> key;
        int keybox[26] = {};
        for (auto s : key) keybox[s - 'a'] = 1;
        int cnt = 0;

        Q.push({0, 0});
        vis[0][0] = true;
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir], ny = cur.Y + dy[dir];
                if (OOB(nx, ny)) continue;
                if (board[nx][ny] == '*' || vis[nx][ny]) continue;
                vis[nx][ny] = true;
                // 열쇠
                if (board[nx][ny] >= 'a' && board[nx][ny] <= 'z'){
                    int c = board[nx][ny] - 'a';
                    keybox[c] = 1;
                    while(!D[c].empty()){
                        auto door = D[c].front(); D[c].pop();
                        Q.push({door.X, door.Y});
                    }
                }
                //문
                else if (board[nx][ny] >= 'A' && board[nx][ny] <= 'Z'){
                    int c = board[nx][ny] - 'A';
                    if (!keybox[c]){
                        D[c].push({nx, ny});
                        continue;
                    }
                }
                else if (board[nx][ny] == '$') cnt++;
                Q.push({nx, ny});
            }
        }
        cout << cnt << "\n";
    }
}