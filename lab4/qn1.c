#include <stdio.h>

int power(int n1, int n2);
int main(){
    int base, pow, res;
    printf("Enter Base: ");
    scanf("%d", &base);
    printf("Enter Power: ");
    scanf("%d", &pow);
    res = power(base, pow);
    printf("Result: %d \n", res);
    return 0;
}

int power(int n1, int n2){
    if(n2!=0) return n1*power(n1, n2-1);
    else return 1;
}