#include <bits/stdc++.h>
using namespace std;

int arr[100000];
int occur[2000000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, count;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;
    count = 0;
    for (int i = 0; i < n; i++){
        if (occur[x - arr[i]] == 1)
            count++;
        occur[arr[i]]++;
    }
    cout << count;
}