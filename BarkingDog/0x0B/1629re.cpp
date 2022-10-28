using ll = long long;
int func(ll a, ll k, ll c){
    if(k == 1) return a % c;
    ll val = func(a, k-1, c);
    val = val*a % c;
    return(val);
}//func는 val에 a를 곱한 값을 c로 나눈 나머지를 반환하는 함수
//k가 성립하면 k+1도 성립하는가? k일 때는 val에 a를 곱한 값을 c로 나눈 나머지를 반환하고 그 값에 또 a를 곱해 c로 나눈 나머지를 반환하는 것을 k번 재귀한다. k+1일 때는 k+1번 재귀함 !