#include <bits/stdc++.h>
using namespace std;
char video[65][65];
int check(int x, int y, int n){
    for(int i = x; i < n+x; i++){
        for(int j = y; j < n+y; j++){
            if(video[i][j] != video[x][y])
                return(0);
        }
    }
    return(1);
}
void answer(int x, int y, int n){
    if(check(x, y, n) == 1){
        cout << video[x][y];
        return;
    }
    cout << '(';
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            answer(x + i*n/2, y + j*n/2, n/2);
        }
    }
    cout << ')';
}
int main(void){
    ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cin >> video[i][j];
	}
	answer(0, 0, n);
}