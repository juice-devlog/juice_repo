#include <stdio.h>

int main()
{
    long long a, r, n;

    scanf("%lld%lld%lld", &a, &r, &n);
    while (--n > 0)
        a *= r;
    printf("%lld", a);
}