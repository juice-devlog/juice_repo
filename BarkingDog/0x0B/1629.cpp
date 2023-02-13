#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int modulo(ll a, ll b, ll c){
    if(b == 1) return a % c; //base condition
    ll val = modulo(a, b / 2, c); //modulo 함수에 b를 2로 나눈 값을 넘겨줌
    val = (val * val) % c; //val에 k의 결과가 들어가있으므로 해당 값을 제곱하여 2k의 결과를 구할 수 있음
    if(b % 2 == 0) return val; //b가 짝수이면 그냥 val 반환(2k의 결과)
    return val * a % c; //b가 홀수이면 한번 더 a 곱하고 c로 나눈 나머지 반환((2k+1)의 결과)
}//modulo 함수는 a의 b승을 c로 나눈 나머지를 반환
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    cout << modulo(a, b, c);
}