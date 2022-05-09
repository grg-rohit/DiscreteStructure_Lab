#include <stdio.h>

int fibonacci(int num);

int main(){
    int n, i=0;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Result: \n");
    while(i<n){
        printf("%d ", fibonacci(i));
        i++;
    }
    return 0;
}

int fibonacci(int num){
    if (num <= 1) return num;
    else return fibonacci(num-1)+fibonacci(num-2);    
}

// #include<stdio.h>    
// void printFibonacci(int n){    
//     static int n1=0,n2=1,n3;    
//     if(n>0){    
//          n3 = n1 + n2;    
//          n1 = n2;    
//          n2 = n3;    
//          printf("%d ",n3);    
//          printFibonacci(n-1);    
//     }    
// }    
// int main(){    
//     int n;    
//     printf("Enter the number of elements: ");    
//     scanf("%d",&n);    
//     printf("Fibonacci Series: ");    
//     printf("%d %d ",0,1);    
//     printFibonacci(n-2);//n-2 because 2 numbers are already printed    
//   return 0;  
//  }    