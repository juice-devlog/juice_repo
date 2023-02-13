#include <stdio.h>

int main()
{
    int i, num, sum;

    scanf("%d", &num);
    sum = 0;

    for (i = 1; ; i++)
    {
        sum += i;
        if (sum >= num)
        {
            printf("%d", sum);
            break;
        }
    }
}