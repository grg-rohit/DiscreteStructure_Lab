#include <iostream>

using namespace std;
int i;
bool p[8] = {true, true, true, true, false, false, false, false};
bool q[8] = {true, true, false, false, true, true, false, false};
bool r[8] = {true, false, true, false, true, false, true, false};
bool x[8], y[8];
int main()
{
    cout<<"p->q = ";
    cout<<"{";
    for(i=0;i<8;i++){
        x[i] = !p[i] | r[i];
        if(!p[i] | q[i] == true){
            cout<< "true,";
        }
        else cout<<"false,";
    }
    cout<<"}\n"<<endl;

    cout<<"q->r = ";
    cout<<"{";
    for(i=0;i<8;i++){
        y[i] = !p[i] | r[i];
        if(!q[i] | r[i] == true){
            cout<< "true,";
        }
        else cout<<"false,";
    }
    cout<<"}\n"<<endl;

    cout<<"p->q = ";
    cout<<"{";
    for(i=0;i<8;i++){
        if(!p[i] | r[i] == true){
            cout<< "true,";
        }
        else cout<<"false,";
    }
    cout<<"}\n"<<endl;

    cout<<"Hypothetical Syllogism because (p->q AND q->r) -> p->r\n"<<endl;

    cout<<"{";
    for(i=0;i<8;i++){

        if((x[i] & y[i]) == true){
            cout<< "true,";
        }
        else cout<<"false,";
    }

    cout<<"}\n"<<endl;
}