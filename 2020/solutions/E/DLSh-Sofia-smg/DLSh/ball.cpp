#include<iostream>
using namespace std;
int main()
{
    long long n,x,t;
    cin>>n>>x;
    long long a=0,b=1,c=2;
        for(n+=0; n!=0; n-=1)
        {
            if(n%2==1)
            {
                t=a;
                a=b;
                b=t;
            }
            else
            {
                t=b;
                b=c;
                c=t;
            }
        }
    if(x==2 && a==2)
    {
        cout<<"0";
    }
    if(x==2 && b==2)
    {
        cout<<"1";
    }
    if(x==2 && c==2)
    {
        cout<<"2";
    }
    if(x==1 && a==1)
    {
        cout<<"0";
    }
    if(x==1 && b==1)
    {
        cout<<"1";
    }
    if(x==1 && c==1)
    {
        cout<<"2";
    }
    if(x==0 && a==0)
    {
        cout<<"0";
    }
    if(x==0 && b==0)
    {
        cout<<"1";
    }
    if(x==0 && c==0)
    {
        cout<<"2";
    }
    cout<<"\n";
    return 0;
}
