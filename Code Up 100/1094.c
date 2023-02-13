#include <stdio.h>

int main()
{
    int arr[10000] = { 0, };
    int i, n, num;

    scanf("%d", &n);
    while (n-- > 0)
    {
        scanf("%d", &num);
        arr[i] = num;
        i++;
    }
    while (--i >= 0)
        printf("%d ", arr[i]);
}