#include <stdio.h>

void primefactors(int num){
    int i;
    printf("Prime Factors: ");
    if(num = 1) printf("%d", num);
    for(i=2; num>1; i++){
        while(num%i==0){
            printf("%d ", i);
            num = num/i;
        }
    }
}

int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    primefactors(num);
   
    return 0;
    
}