#include <stdio.h>

int main()
{
    int arr[101][101];
    int h, w, n, l, d, x, y;
    int i, j;

    scanf("%d%d%d", &h, &w, &n);
    for ( ; n > 0; n--)
    {
        scanf("%d%d%d%d", &l, &d, &x, &y);
        for (i = 1; i <= h; i++)
        {
            for (j = 1; j <= w; j++)
            {
                if (i == x && j == y)
                {
                    arr[i][j] = 1;
                    if (d == 0)
                    {
                        for (l -= 1 ; l > 0; l--)
                            arr[i][j + l] = 1;
                    }
                    else
                    {
                        for (l -= 1 ; l > 0; l--)
                            arr[i + l][j] = 1;
                    }
                    break;
                }
            }
        }
    }
    for (i = 1; i <= h; i++)
    {
        for (j = 1; j <= w; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}