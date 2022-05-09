#include <iostream>

using namespace std;
int i;
bool p[8] = {true, true, true, true, false, false, false, false};
bool q[8] = {true, true, false, false, true, true, false, false};
bool r[8] = {true, false, true, false, true, false, true, false};
bool a[8], b[8], c[8];
int main()
{
    for(i=0;i<8;i++){
        a[i] = p[i] | q[i];
    }

    for(i=0;i<8;i++){
        b[i] = !(p[i] & q[i]) | r[i];
    }
    for(i=0;i<8;i++){
        c[i] = q[i] & !r[i];
    }
    cout<<"{";
    for(i=0;i<8;i++){
        if(!a[i] & b[i] & c[i] | !p[i] == true){
            cout << "true, ";
        }
        else cout << "false, ";
    }
    cout<<"}\n\n";
    cout<<"Verification: \n";
     cout<<"{";
    for(i=0;i<8;i++){
        if(!p[i] == true){
            cout << "true, ";
        }
        else cout << "false, ";
    }
    cout<<"}";
}