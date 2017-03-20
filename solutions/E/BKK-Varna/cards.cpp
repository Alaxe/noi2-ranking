#include <iostream>
using namespace std;
int main () {
int n,a1,b1,a2,b2,br,am1=0,am2=0;
cin>>n;
cin>>a1>>b1;
for (br=2;br<=n;br++) {
    cin>>a2>>b2;
    if (a2<=a1||a1<=b2) {
        if (b1<=b2||b2<=a1) {
            if (am1>am2) {am2=am1;}
            am1=am1 + 1;
        }else {am1 = 0;}
    }
    a1=a2;
    b1=b2;
}
cout<<am2;
return 0;
}
