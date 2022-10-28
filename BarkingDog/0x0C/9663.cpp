#include <bits/stdc++.h>
using namespace std;

/*const int MX = 15;
int n, cnt = 0;
int chess[MX];

int isValid(int row, int col){
    for(int check_row = 0; check_row < row; check_row++){
        if(abs(row-check_row) == abs(col-chess[check_row]) || chess[check_row] == col) return(0);
    }
    return(1);
}

void func(int row){
    if(row == n){
        cnt++; return;
    }
    for(int col = 0; col < n; col++){
        if(isValid(row, col) == 0) continue;
        chess[row] = col;
        func(row+1);
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    func(0);
    cout << cnt;
}*/

bool row[40];
bool diag_r[40];
bool diag_l[40];

int cnt = 0;
int n;
void func(int cur){
    if(cur == n){
        cnt++;
        return;
    }
    for(int i = 0; i < n; i++){
        if(row[i] || diag_r[i+cur] || diag_l[cur-i+n-1]) continue;
        row[i] = 1;
        diag_r[i+cur] = 1;
        diag_l[cur-i+n-1] = 1;
        func(cur+1);
        row[i] = 0;
        diag_r[i+cur] = 0;
        diag_l[cur-i+n-1] = 0;
    }
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    func(0);
    cout << cnt;
}