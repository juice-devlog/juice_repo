#include <stdio.h>
#pragma warning(disable:4996)

int calculate(char op, int val, int num){
    if(op == '+') return(val + num);
    if(op == '-') return(val - num);
    if(op == '*') return(val * num);
    if(op == '/') return(val / num);
}
int main(void){
    int num, val;
    char op;
    scanf("%d", &val);
    while(1){
        scanf("%c", &op);
        if(op == '=') break;
        scanf("%d", &num);
        val = calculate(op, val, num);
    }
    printf("%d", val);
}