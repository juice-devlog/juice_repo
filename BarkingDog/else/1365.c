#include <stdio.h>

void print_star(int i, int n){
    printf("*");
    for(int space = 0; space < i-1; space++) printf(" ");
    printf("*");
    for(int space = 0; space < n - (i+1)*2; space++) printf(" ");
    if(i != n/2) printf("*");
    for(int space = 0; space < i-1; space++) printf(" ");
    printf("*\n");
}
int main(void){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) printf("*");
    printf("\n");
    for(int i = 1; i < n/2; i++) print_star(i, n);
    if(n%2 == 1) print_star(n/2, n);
    for(int i = n/2 - 1; i >= 1; i--) print_star(i, n);
    for(int i = 0; i < n; i++) printf("*");
}