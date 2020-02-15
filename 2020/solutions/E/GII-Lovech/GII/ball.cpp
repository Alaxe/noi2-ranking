#include <iostream>
using namespace std;
int main()
{
    int x,n,a0,a1,a2;
    cin>>n;
    cin>>x;
    if(x==0)
    {
        a0=1;
    }
    if(x==1)
    {
        a1=1;
    }
    if(x==2)
    {
        a2=1;
    }
    for(int i=0; i<=n; i++)
    {
        if(i%2==0)
        {
            swap(a0,a1);
        }
        else
        {
            swap(a2,a1);
        }
    }
    if(a1==1)
    {
        cout<<"1"<<endl;
    }
    if(a2==1)
    {
        cout<<"2"<<endl;
    }
    if(a0==1)
    {
        cout<<"0"<<endl;
    }


    return 0;
}
