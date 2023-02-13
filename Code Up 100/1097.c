#include <stdio.h>

int main()
{
    int arr[20][20] = { 0, };
    int x, y, n;
    int i, j;

    for (i = 1; i < 20; i++)
    {
        for (j = 1; j < 20; j++)
            scanf("%d", &arr[i][j]);
    }

    scanf("%d", &n);

    for ( ; n > 0; n--)
    {
        scanf("%d%d", &x, &y);
        for (i = 1; i < 20; i++)
        {
            for (j = 1; j < 20; j++)
                if (i == x && j == y)
                    continue;
                else if (i == x || j == y)
                    arr[i][j] = !arr[i][j];
        }
    }
    for (i = 1; i < 20; i++)
    {
        for (j = 1; j < 20; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}