#include <stdio.h>

int main()
{
    int i, sum, num;

    scanf("%d", &num);
    sum = 0;

    for (i = 1; sum < num; i++)
        sum += i;
    printf("%d", i - 1);
}