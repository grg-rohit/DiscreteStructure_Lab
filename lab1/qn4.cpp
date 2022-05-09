#include <iostream>
using namespace std;

class people{
    int age;
    string name;

    public:
    

    void setName(){
        cout<<"Enter Name: ";
        cin>>name;
    }

    void setAge(){
        cout<<"Enter Age: ";
        cin>>age;
    }

    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }

    void fuzzySetA(){
        float degree;
        if(age<=20) degree = 1;
        else if(age>20 && age<=30) degree = (float)(30-age)/10;
        else degree = 0;
        cout<<"Degree of membership: "<<degree<<endl;
    }

    void fuzzySetB(){
        float degree;
        if(age<=15) degree = 1;
        else if(age>15 && age<=35) degree = (float)(35-age)/20;
        else degree = 0;
        cout<<"Degree of membership: "<<degree<<endl;
    }


};

int main(){
    people fuzz[5];

    for(int i=0; i<5; i++){
        fuzz[i].setName();
        fuzz[i].setAge();
    }
    cout<<endl;
   
    cout<<"fuzzy set for 4a"<<endl;
    for(int i=0; i<5; i++){
        fuzz[i].display();
        fuzz[i].fuzzySetA();
        cout<<endl;
        
    }
    cout<<"fuzzy set for 4b"<<endl;
    for(int i=0; i<5; i++){
        fuzz[i].display();
        fuzz[i].fuzzySetA();
        cout<<endl;
        
    }

    return 0;
}



