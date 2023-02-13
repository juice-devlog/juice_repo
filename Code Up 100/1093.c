#include <stdio.h>

int main()
{
    int arr[23] = { 0, };
    int i, n, num;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num);
        arr[num - 1] ++;
    }
    for (i = 0; i < 23; i++)
        printf("%d ", arr[i]);
}