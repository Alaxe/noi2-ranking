#include <iostream>
using namespace std;

int main()
{
    int m,k,y,z=999999999,a=0,b,c;
    cin>>m>>k;
    for(int x=1 ; x<=200; x++)
    {
        c=z-y;
        cin>>y;

        if(y%2==0)
        {
            a=a+y;
        }

        if(z-y>c)
        {
            b=x;
            z=y;
        }

        if(a>k||x==200)
        {
            cout<<b<<" "<<a<<endl;
            return 0;
        }
    }

}
