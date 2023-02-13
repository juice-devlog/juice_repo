#include <stdio.h>

int main()
{
    long long a, b, c;

    scanf("%lld%lld%lld", &a, &b, &c);
    printf("%lld\n%.1f", a + b + c, (float)(a + b + c) / 3);
}