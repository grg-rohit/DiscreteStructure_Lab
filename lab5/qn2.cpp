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
int combin(int n, int r){
    return fact(n)/(fact(r)*fact(n-r));
}

int main()
{
 int n,r;
 cout<<"Enter n: ";
 cin>> n;
 cout<<"Enter r: ";
 cin>> r;

 cout<<"Combination of (" <<n << ","<< r << ") is: " << combin(n,r)<<endl;

}