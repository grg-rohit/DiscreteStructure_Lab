#include <stdio.h>
int gcd(int num1, int num2){
    // int result, i;
    // for(i=1; i<=num1 && i <=num2; ++i){
    //     if(num1%i==0 && num2%i==0)
    //         result = i;
    // }
    // return result;

    if(num1==0) return num2;

    return gcd(num2%num1, num1);
    
}

int gcdExtended(int num1, int num2, int *x, int *y){
    if(num1==0){
        *x=0; 
        *y=0;
        return num2; 
    }
    int x1, y1; 
    int gcd = gcdExtended(num2%num1, num1, &x1, &y1);
 
    *x = y1 - (num2/num1) * x1;
    *y = x1;
 
    return gcd;
}

int main(){
    int x, y;
    int g =  gcdExtended(35, 15, &x, &y);
    printf("GCD(35, 15) = %d\n", g);
    return 0;
}

