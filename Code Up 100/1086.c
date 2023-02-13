#include <stdio.h>

int main()
{
    long long w, h, b;

    scanf("%lld%lld%lld", &w, &h, &b);
    printf("%.2f MB", w * h * b / 8.0 / 1024.0 / 1024.0);
}