#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int draw[502][502];
bool vis[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, info, count = 0;
    cin >> n >> m; // 그림의 세로 크기 n, 가로 크기 m
    queue<pair<int, int> > S;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> info;
            draw[i][j] = info; // 그림 정보 채우기
            if((j == 0 || (draw[i][j - 1] == 0)) && (i == 0 || (draw[i - 1][j] == 0)) && info == 1){
                S.push({i, j}); // 시작점 큐에 저장
                count++; // 그림 개수 세기
            }
        }
    }
    queue<pair<int, int> > Q;
    int max_size = 0;
    for(int i = 0; i < count; i++){
        pair<int, int> start = S.front(); S.pop();
        Q.push({start.X, start.Y});
        vis[start.X][start.Y] = 1;
        int size = 1;
        while(!Q.empty()){
            pair<int, int> cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(vis[nx][ny] || draw[nx][ny] != 1) continue;
                vis[nx][ny] = 1;
                Q.push({nx, ny});
                size++;
            }
        }
        if(size > max_size) max_size = size;
    }
    cout << count << '\n' << max_size;
}