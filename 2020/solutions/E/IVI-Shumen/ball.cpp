#include<iostream>
#include<cmath>
using namespace std;
int main()
{
long long int n,x;
cin>>n;
cin>>x;
long long int br=0;
long long int a1=0,a2=1,a3=2;
for(int i=1;i<=n;i++)
{
    br++;
    if(x==a3)
    {
        if(br%2==0)
        {
           swap(a2,x);
        }
    }
    if(x==a1)
    {
        if(br%2!=0)
        {
            swap(x,a2);
        }
    }
    if(x==a2)
    {
        if(br%2!=0)
        {
            swap(x,a1);
        }
        if(br%2==0)
        {
            swap(a3,x);
        }
    }
}
cout<<x<<endl;
return 0;
}
