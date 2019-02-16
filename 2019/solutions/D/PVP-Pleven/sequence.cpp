#include<iostream>
using namespace std;
int a[1000000],i;
int main()
{
    int m,n,p=0;
    cin>>m>>n;
    a[1]=1;
    for(i=2; i<=100; i++)
    {
        for(i=1; i<=p/2; i++)
        {
            a[i]=i;
        }
        for(i=p/2; i>1; i--)
        {
            a[i]=i;
        }
        p+=2;
        cout<<p;
    }
    for(i=1;i<=100; i++)
    {
        cout<<a[i];
    }
    return 0;
}
