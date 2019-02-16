#include<iostream>
using namespace std;
int main()
{
    int i,y=1,j=0,x=1,n,k,d=2;
    bool p=true;
    cin>>n>>k;
    if (n!=1)
    {
        for (i=1;i<n;i++)
        {
            x=x+d;
            y=y+2;
            d=d+2;
        }
    }
    if (k==1) cout<<x<<endl;
    else
    {
        for (i=1;i<k;i++)
        {
            if (p==true) {x=x+y;p=false;}
            else {x=x+(j+2);j=j+2;p=true;}
        }
        cout<<x<<endl;
    }
    return 0;
}
