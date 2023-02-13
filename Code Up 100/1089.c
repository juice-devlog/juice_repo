#include <stdio.h>

int main()
{
    int a, d, n;

    scanf("%d%d%d", &a, &d, &n);
    while (--n > 0)
        a += d;
    printf("%d", a);
}