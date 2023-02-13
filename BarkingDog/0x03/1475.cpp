#include <iostream>
using namespace std;

int arr[10];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, div, max;
    cin >> n;
    while (n != 0){
        div = n % 10;
        if (div == 6 && arr[9] < arr[6])
            arr[9]++;
        else if (div == 9 && arr[6] < arr[9])
                arr[6]++;
        else{
            for (int i = 0; i < 10; i++){
                if (i == div)
                    arr[i]++;
            }
        }
        n = n / 10;
    }
    max = 0;
    for (int i = 0; i < 10; i++){
        if (arr[i] > max)
            max = arr[i];
    }
    cout << max;
}