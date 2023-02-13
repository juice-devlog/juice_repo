#include <stdio.h>

int main()
{
    int n, nbr;

    scanf("%d", &n);

get_nbr:
    scanf("%d", &nbr);
    printf("%d\n", nbr);

    if (--n != 0)
        goto get_nbr;
}