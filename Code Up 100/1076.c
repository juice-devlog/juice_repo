#include <stdio.h>

int main()
{
    char    c, alpha;

    scanf("%c", &alpha);
    c = 'a';

    do
    {
        printf("%c ", c);
        c++;
    } while (c <= alpha);
}