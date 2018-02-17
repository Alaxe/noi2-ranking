#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
    unsigned long long int brsis,a[4];
    cin>>brsis;
    cin>>a[0]>>a[1]>>a[2]>>a[3];
    for(int t=0; t<=3; t++)
    {
        int x=a[t],p=1;
        for(; x>=9; x/=10)
            p*=10;
        int del=p;
        p+=p/10;
        int p2,f=0;
        for(; p<a[t]; p++)
        {
            p2=(p%del)*10+p/del;
            if(abs(p-p2)==a[t])
            {
                cout<<p<<"\n";
                f=1;
                p=a[t];
            }
        }
        if(f==0)
        cout<<"0\n";
    }
    return 0;
}
/*
10
216
1318
2349
44444
*/
