#include <iostream>
using namespace std;
int main () {
    long long  a,b,x,ch,y=0;
    cin >>a >>b;
    x=a-1;
    ch=1;
    while (x>0) {
        ch=ch*10;
        x--;
    }
    if (ch%b==0) {
        cout <<ch<<endl;
    }
    else {
            ch=ch+(b-ch%b);
    cout <<ch<<endl;
    }
return 0;
}
