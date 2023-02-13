#include <bits/stdc++.h>
using namespace std;
n개일 경우
k번째는 k보다 큰 원판에만 올라갈 수 있음
우선 n보다 작은 애들을 쭈루룩 쌓아올려야 댐(n이 짝수 개면 그 쌓아올리는 거를 2번째부터 시작해야 하구 홀수면 3번째부터 시작해야 한당)
그다음 제일 n부터 3번째로 넘기기
다 넘기고 나면 남은 애들 중에 제일 큰 친구 남기고 또 탑쌓기
우리가 쓸 재귀함수가 할 일
우선 k를 받고 k-1을 가장 아래로 둔 탑 쌓기(처음에는 제일 큰 친구 3으로 넘겨야 하니까 2에다가 탑 쌓아두고 그 이후에는 제일 큰 친구가 있는 위치를 기준으로 비어있는 곳에 탑 쌓기)
k-1개를 옮길 수만 있다면 k도 옮길 수 있다 !
void hanoi(int a, int b, int n){
    if(n == 1){
        cout << a << ' ' << b << '\n';
        return;
    }//제일 위에 있는 친구를 a에서 b로 옮기는 것을 출력
    hanoi(a, 6-a-b, n-1);//a의 위치에 있는 탑들을 n-1개만큼 다른 기둥으로 옮기겠다
    cout << a << ' ' << b << '\n';//n-1개의 탑을 모두 옮긴 후 마지막에 남은 가장 큰 탑을 a에서 b로 옮기는 것을 출력
    hanoi(6-a-b, b, n-1);//현재 위치에서 목표(b)위치로 옮기겠다
}//hanoi 함수는 n개의 탑을 a 위치에서 b 위치로 옮기는 함수
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    cout << (1<<k) - 1 << '\n';
    hanoi(1, 3, k);
}