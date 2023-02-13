#include <stdio.h>

int main()
{
    char    c;

    scanf("%c", &c);

    while(c != 'q')
    {
        printf("%c", c);
        scanf("%c", &c);
    }
    printf("%c", c);
}