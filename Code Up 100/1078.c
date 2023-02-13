#include <stdio.h>

int main()
{
    int n, sum;

    scanf("%d", &n);
    sum = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            sum += i;
    }

    printf("%d", sum);
}