#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long int n;
    int x;
    cin>>n>>x;
    int a=0,b=1,c=2;
    for(long long int i=1;i<=n%6;i++)
    {
        if(i%2==0)
        {
            swap(b,c);
        }
        if(i%2!=0)
        {
            swap(a,b);
        }
    }
    if(x==0)
    {
        cout<<a<<endl;
    }
    if(x==1)
    {
        cout<<b<<endl;
    }
    if(x==2)
    {
        cout<<c<<endl;
    }
    return 0;
}
