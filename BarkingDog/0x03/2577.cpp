#include <iostream>
using namespace std;

int arr[10];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a, b, c, num, div;
    cin >> a >> b >> c;
    num = a * b * c;
    while (num != 0){
        div = num % 10;
        for (long long i = 0; i < 10; i++){
            if (i == div)
                arr[i]++;
        }
        num = num / 10;
    }
    for (int i = 0; i < 10; i++) cout << arr[i] << '\n';
}