
#include <iostream>

using namespace std;
int i;
bool p[8] = {true, true, true, true, false, false, false, false};
bool q[8] = {true, true, false, false, true, true, false, false};
bool r[8] = {true, false, true, false, true, false, true, false};
bool a[8], b[8], c[8], d[8];
int main()
{
   cout<<"a. \n";
   for(i=0;i<8;i++){
    a[i] = p[i] & !q[i] | r[i];
    b[i] = !p[i] | r[i];
   }
   cout<<"(p^~q v r) -> (~p v r)\n";
   cout<<"{";
   for(i=0;i<8;i++){
    if(!a[i] | b[i] == true){
        cout<< "true, ";
    }
    else cout<<"false, ";
   }
   cout<<"}\n\n";

    cout<<"b. \n";
   for(i=0;i<8;i++){
    a[i] = p[i] & !q[i] | r[i];
    b[i] = !p[i] | r[i];
    c[i] = !a[i] | b[i];
    d[i] = !b[i] | a[i];
   }
   cout<<"(p^~q v r) <-> (~p v r\n";
   cout<<"{";
   for(i=0;i<8;i++){
    if(c[i] & d[i] == true){
        cout<< "true, ";
    }
    else cout<<"false, ";
   }
   cout<<"}\n\n";


}