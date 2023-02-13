#include <bits/stdc++.h>
using namespace std;

int a[500005];
int n;

int lower_idx(int target)
{
    int st = 0;
    int en = n;
    while(st < en)
    {
        int mid = (st + en) / 2;
        if(a[mid] < target)
            st = mid + 1;
        else if(a[mid] >= target)
            en = mid;
    }
    return st;
}

int upper_idx(int target)
{
    int st = 0;
    int en = n;
    while (st < en)
    {
        int mid = (st + en) / 2;
        if (a[mid] <= target)
            st = mid + 1;
        else if (a[mid] > target)
            en = mid;
    }
    return en;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int m;
    cin >> m;
    while(m--)
    {
        int num;
        cin >> num;
        cout << upper_idx(num) - lower_idx(num) << ' ';
    }
}