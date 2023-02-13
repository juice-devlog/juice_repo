#include <stdio.h>

int main()
{
    char    arr[21];

    scanf("%s", arr);
    for(int i = 0; arr[i]; i++)
        printf("\'%c\'\n", arr[i]);
}