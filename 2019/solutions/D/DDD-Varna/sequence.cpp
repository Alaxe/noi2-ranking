#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n,m;
    int r,o,poz;
    if(m==1)
    {
        r=n;
        poz=((n+(n-1))-1)/2 +1;
    }
    else
    {
        r=n+(m/2);
        if(m%2==0)
        {
            poz=(r+(r-1))-1; //r+(r-1) - дължина на реда
        }
        else
        {
            poz=m*n+n-1;
        }
    }
    o=poz+r+(n-1)+(n-1);

        cout<<o;
    }

