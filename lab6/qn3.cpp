#include <iostream>
#include <stdbool.h>

//1(A)#define n 4
#define n 5
using namespace std;
void isReflexive(int mat[][n]){
    int flag = 0;
    for(int i = 0; i < n; i++){
        if(!mat[i][i]){
            flag = 1;
            break;
        }
    }
    if(flag){
        cout<<"It is not Reflexive\n";
    }
    else{
        cout<<"It is reflexive\n";
    }
}

void issymmetric(int mat[][n]){
    int flag = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                break;
            }
            if(mat[i][j] != mat[j][i]){
                flag = 1;
                break;
            }
        }
    }

    if(flag){
        cout<<"It is not symmetric.\n";
    }
    else{
        cout<<"It is symmetric.\n";
    }
}

void isassymmetric(int mat[][n]){


    int flag = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
           if(mat[i][j] == mat[j][i] && mat[i][j] != 0){
                flag = 1;
                break;
            }
        }
    }
    if(flag){
        printf("It is not assymmetric.\n");
    }
    else{
        printf("It is assymmetric.\n");
    }
}

void isantiymmetric(int mat[][n]){

    int flag = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == mat[j][i] && mat[i][j] != 0 && i != j){
                flag = 1;
                break;
            }
        }
    }
    if(flag){
        cout<<"It is not antisymmetric.\n";
    }
    else{
        cout<<"It is antisymmetric.\n";

    }
}

bool checkTransitive(int start, int end, int mat[][n]){
    for(int otherEnd = 0; otherEnd < n; otherEnd++){
        if(mat[end][otherEnd]){
            if(!mat[start][otherEnd]){
                return false;
            }
        }
    }
    return true;

}

void isTransitive(int mat[][n]){
    int flag = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j]){
                if(!checkTransitive(i, j, mat)){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag){
            cout<<"It is not transitive.\n";
            break;
        }
    }
    if(!flag){
        cout<<"It is transitive.\n";
    }
}

int main(){
    /*
    cout<<"1(A)"<<endl;
    int mat[4][4] = {{1, 1, 1, 1},
                    {0, 0, 0, 1},
                    {1, 1, 0, 0},
                    {0, 1, 1, 1}};

    isantiymmetric(mat);
    isassymmetric(mat);
    isReflexive(mat);
    issymmetric(mat);
    isTransitive(mat);
    */

    cout<<"1(B)"<<endl;
    int mat[5][5] = {{0, 1, 0, 1, 0},
                    {1, 0, 1, 0, 1},
                    {0, 1, 1, 0, 1},
                    {1, 0, 0, 0, 1},
                    {0, 0, 1, 0, 1}};

    isantiymmetric(mat);
    isassymmetric(mat);
    isReflexive(mat);
    issymmetric(mat);
    isTransitive(mat);


    return 0;
}
