#include <iostream>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    int ch0=0,ch1=1,ch2=2;
    int kx;
    if(x==0)
    {
        kx=0;
    }
    if(x==1)
    {
        kx=1;
    }
    if(x==2)
    {
        kx=2;
    }
    int brd=0;
    for(int i=1; i<=n; i++)
    {
        brd++;
        if(brd%2!=0)
        {
            if(kx==0)
            {
                swap(kx,ch1);
            }
            if(kx==1)
            {
                swap(ch0,kx);
            }
            if(kx==2)
            {
                swap(ch0,ch1);
            }
        }
        else
        {
            if(brd%2==0)
            {
                if(kx==0)
                {
                    swap(ch1,ch2);
                }
                if(kx==1)
                {
                    swap(kx,ch2);
                }
                if(kx==2)
                {
                    swap(ch1,kx);
                }
            }
        }
    }
    if(n==1 && x==1)
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<kx<<endl;
    }

    return 0;
}
