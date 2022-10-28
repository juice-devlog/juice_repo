#include <bits/stdc++.h>
using namespace std;
int count_minus = 0, count_zero = 0, count_plus = 0;
int paper[2200][2200];
int check(int x, int y, int n){
    for(int i = x; i < n+x; i++){
        for(int j = y; j < n+y; j++){
            if(paper[i][j] != paper[x][y])
                return(0);
        }
    }
    return(1);
}
void answer(int x, int y, int n){
    if(check(x, y, n) == 1){
        if(paper[x][y] == -1) count_minus++;
        if(paper[x][y] == 0) count_zero++;
        if(paper[x][y] == 1) count_plus++;
        return;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            answer(x + i*n/3, y + j*n/3, n/3);
        }
    }   
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin >> paper[i][j];
    }
    answer(0, 0, n);
    cout << count_minus << '\n' << count_zero << '\n' << count_plus;
}