#include <stdio.h>

int main()
{
    int arr[11][11] = { 0, };
    int i, j;

    for (i = 1; i < 11; i++)
    {
        for (j = 1; j < 11; j++)
            scanf("%d", &arr[i][j]);
    }

    i = 2;
    j = 2;
    if (arr[i][j] != 0)
    {
        if (arr[i][j] == 2)
            arr[i][j] = 9;
        for (i = 1; i < 11; i++)
        {
            for (j = 1; j < 11; j++)
                printf("%d ", arr[i][j]);
            printf("\n");
        }
        return (0);
    }
    
    arr[i][j] = 9;
    while (!(arr[i][j] == 1 || arr[i + 1][j] == 1 && arr[i][j + 1] == 1)) // 오른쪽과 아래가 막혀있으면 멈춤 (갈 곳이 없다 !)
    {
        j++;
        if (arr[i][j] == 2) // 만약 오른쪽으로 한 칸 이동한 곳에 먹이가 있으면 멈춤
        {
            arr[i][j] = 9;
            break;
        }
        while (arr[i][j] == 0) // 장애물이면 멈춰야 함
        {
            arr[i][j] = 9;
            j++;
        } // 처음 시작한 곳에서 오른쪽 장애물 만날 때까지 직진
        i++; // 아래쪽으로 한 칸 이동
        j--; // 조건식 검사하느라 하나 +된 j 값 빼주기
        if (arr[i][j] == 2) // 만약 아래쪽으로 한 칸 이동한 곳에 먹이가 있으면 멈춤
        {
            arr[i][j] = 9;
            break;
        }
        while (arr[i][j] == 0 && arr[i - 1][j + 1] != 0) // 장애물을 만나거나 오른쪽 길 찾으면 멈춰야 함
        {
            arr[i][j] = 9;
            i++;
        } // 멈춘 곳에서 아래쪽 장애물 만날 때까지 직진
        i--; // 조건식 검사하느라 하나 +된 i 값 빼주기
    }
    for (i = 1; i < 11; i++)
    {
        for (j = 1; j < 11; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}