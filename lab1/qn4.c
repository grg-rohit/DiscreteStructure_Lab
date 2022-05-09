#include <stdio.h>
#include <conio.h>

int main(){
    char names[5];
    int age[5];
    int i;
    for(i=0; i<5; i++){
        printf("Enter Name: ");
        scanf("%[A-Za-z ]s", names[i]);
        printf("Enter Age: ");
        scanf("%d", &age[i]);
    }

    for(i=0; i<5; i++){
        printf("Name:%s", names[i]);
    }
}

int memFunc_a(int n){
    int degree;
    if(n<=20) degree = 1;
    else if(n>20 && n<=30) degree = (30-n)/10;
    else degree = 0;
    printf("Degree of membership: %d", degree);
}

int memFunc_b(int n){
    int degree;
    if(n<=15) degree = 1;
    else if(n>15 && n<=35) degree = (35-n)/20;
    else degree = 0;
    printf("Degree of membership: %d", degree);
}