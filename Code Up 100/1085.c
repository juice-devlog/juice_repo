#include <stdio.h>

int main()
{
    long long h, b, c, s;

    scanf("%lld%lld%lld%lld", &h, &b, &c, &s);
    printf("%.1f MB", h * b * c * s / 8.0 / 1024.0 / 1024.0);
}