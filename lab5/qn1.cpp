#include <iostream>

using namespace std;

int fact(int a){
    if(a!=0){
       return a* fact(a-1);
    }
    else{
        return 1;
    }
}


int permut(int n, int r){
    return fact(n)/fact(n-r);
}

int main()
{
 int n,r;
 cout<<"Enter n: ";
 cin>> n;
 cout<<"Enter r: ";
 cin>> r;

 cout<<"Permutation of " <<n << " and "<< r << " is: " << permut(n,r)<<endl;
 

}