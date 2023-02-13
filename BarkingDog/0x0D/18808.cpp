#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int sticker[12][12];
bool laptop[42][42];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int size(int x, int y){
    for(int i = 0; i < 4; i++){
        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                x += dx[i];
                y += dy[i];
                int 

        if (x < 0 || y < 0 || x >= n || y >= m) return(0);
        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                if(laptop[x][y] != sticker[])
            }
        }
    }
}

void solve(int idx){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(laptop[i][j] == 0){
                if(size(i, j) != 0) 
                    size += size(i, j); continue;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for(int i = 0; i < K; i++){
        int R, C;
        cin >> R >> C;
        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++)
                cin >> sticker[r][c];
        }
        solve(i);
    }
}