
#include <iostream>
//program to find cartesian products
using namespace std;

int getSet(int *arr, int n){

    for(int i=0; i<n; i++){
        cin>>*(arr + i);
    }
    return *arr;
}

void dispSet(int *arr, int n){
    for(int i=0; i<n; i++){
        cout<<*(arr+i)<<" ";
    }
}

int findCart(int *arr1, int *arr2, int n, int n1){
    for(int i=0; i<n; i++){
        cout<<"{";
        for(int j=0; j<n1; j++){
            cout<<"{"<< arr1[i]<<","<<arr2[j]<<"}";
        }
        cout<<"}";
    }
}

int main(){
    
    int size1, size2;

    cout<<"Enter the size of First set: ";
    cin>>size1;
    cout<<"Enter the size of Second set: ";
    cin>>size2;
    int *arr1 = new int[size1];
    int *arr2 = new int[size2];
    cout<<"Enter Elememts of First Set: \n";
    getSet(arr1, size1);
    dispSet(arr1, size1);
    cout<<"\nEnter Elememts of First Set: \n";
    getSet(arr2, size2);
    dispSet(arr2, size2);

    cout<<"\n";
    findCart(arr1, arr2, size1, size2);

    delete []arr1;
    
    return 0;
}