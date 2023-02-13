#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans = 65;
int room[10][10];
vector<pair <int, int> > cctv_pos;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void check(int x, int y, int dir){
    dir %= 4;
    while(1){
        x += dx[dir];
        y += dy[dir];
        if(x < 0 || y < 0 || x >= n || y >= m) return;
        if(room[x][y] == 6) return;
        if(room[x][y] != 0) continue;
        room[x][y] = 7;
    }
}

void func(int k){
    int num = cctv_pos.size();
    if(k == num){
        int tmp = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(room[i][j] == 0) tmp++;
            }
        }
        ans = min(ans, tmp);
        return;
    }
    int x = cctv_pos[k].first;
    int y = cctv_pos[k].second;
    int save[10][10];
    for(int dir = 0; dir < 4; dir++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                save[i][j] = room[i][j];
            }
        }
        if(room[x][y] == 1) check(x, y, dir);
        else if(room[x][y] == 2){
            check(x, y, dir);
            check(x, y, dir+2);
        }
        else if(room[x][y] == 3){
            check(x, y, dir);
            check(x, y, dir+1);
        }
        else if(room[x][y] == 4){
            check(x, y, dir);
            check(x, y, dir+1);
            check(x, y, dir+2);
        }
        else if(room[x][y] == 5){
            check(x, y, dir);
            check(x, y, dir+1);
            check(x, y, dir+2);
            check(x, y, dir+3);
        }
        func(k+1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                room[i][j] = save[i][j];
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int idx = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> room[i][j];
            if(room[i][j] >= 1 && room[i][j] <= 5)
                cctv_pos.push_back({i, j});
        }
    }
    func(0);
    cout << ans;
}