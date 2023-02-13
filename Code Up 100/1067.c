#include <stdio.h>

int main()
{
    long long a;

    scanf("%lld", &a);
    if (a < 0)
    {
        printf("minus\n");
        a == -a;
    }
    else
        printf("plus\n");
    if (a % 2 == 0)
        printf("even\n");
    else
        printf("odd\n");
}