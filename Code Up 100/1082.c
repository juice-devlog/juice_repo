#include <stdio.h>

int main()
{
    int i, n;

    scanf("%X", &n);
    for(i = 1; i <= 15; i++)
        printf("%X*%X=%X\n", n, i, n * i);
}