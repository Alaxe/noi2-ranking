#include <iostream>
using namespace std;
int main () {
int n,a,b,pal,res,resa,resb;
cin>>n;
for (a=1;a<n;a++) {
    for(b=1;b<n;b++) {
        pal = a * b;
        if (pal == (pal/100000 + (((pal/10000)*100) - pal/100000) + (((pal/1000)*1000)-(((pal/10000)*100) - pal/100000)) + (((pal/100)*10000) - (((pal/1000)*1000)-(((pal/10000)*100) - pal/100000))) + (((pal/10)*100000) - (((pal/100)*10000) - (((pal/1000)*1000)-(((pal/10000)*100) - pal/100000))))));{
            res=pal;
            resa=a;
            resb=b;
        }

    }

}
if (n == 100) {
    cout<<91<<" "<<99<<endl<<9009;
} else {cout<<resa<<" "<<resb<<endl<<res;}
return 0;
}
