#2
#include <iostream>

using namespace std;
int i;
bool p[8] = {true, true, true, true, false, false, false, false};
bool q[8] = {true, true, false, false, true, true, false, false};
bool r[8] = {true, false, true, false, true, false, true, false};

int main()
{
    cout<<"Whenever p implies q and ~q are both true then p is also true..."<<endl;

    for(i = 0; i<8; i++){
        cout<<"p->q = ";
        cout<< "{";
        for(i=0;i<8;i++){
            if ((!p[i] | q[i])== true){
                cout<< "true,";
            }
            else cout<<"false,";
        }
        cout<<"}\n"<<endl;
    }
    for(i = 0; i<8; i++){
        cout<<"~q = ";
        cout<< "{";
        for(i=0;i<8;i++){
            if (!q[i] == true){
                cout<< "true,";
            }
            else cout<<"false,";
        }
        cout<<"}\n"<<endl;
    }
    for(i = 0; i<8; i++){
        cout<<"~p = ";
        cout<< "{";
        for(i=0;i<8;i++){
            if (!p[i] == true){
                cout<< "true,";
            }
            else cout<<"false,";
        }
        cout<<"}\n"<<endl;
    }

    cout<<"Modus tollens: (~p is true only when both p->q and ~q are true...\n"<<endl;
    cout<<"{";
    for(i=0;i<8;i++){
        for(i=0;i<8;i++)
        if((!(p[i]| q[i]) && !q[i]) == true){
            cout << "true, ";
        }
        else cout<<"false, ";

    }
    cout << "}\n";

    return 0;
}