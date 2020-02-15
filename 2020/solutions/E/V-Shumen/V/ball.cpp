#include<iostream>
#include<cmath>
using namespace std;
int main()
{
long long int n;
int x;
cin>>n>>x;
int a=0,b=1,c=2;
if(x==a)
        {
            b=0;
            c=0;
            a=1;
        }
        else
        {
            if(x==b)
            {
                a=0;
                c=0;
                b=1;
            }
            else
            {
                a=0;
                b=0;
                c=1;
            }
        }
    for(long long int i=n;i>=1;i--)
    {
        if(i%2==0)
        {
            swap(b,c);
        }
        else
        {
            swap(b,a);
        }
    }
    if(a>b&&a>c)
    {
        cout<<0<<endl;
    }
    if(b>a&&b>c)
    {
        cout<<1<<endl;
    }
    if(c>b&&c>a)
    {
        cout<<2<<endl;
    }
	return 0;
}
