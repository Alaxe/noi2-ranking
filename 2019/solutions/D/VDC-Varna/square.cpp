#include<iostream>
#include<cmath>
using namespace std;
int divide(int n)
{
    int d=sqrt(n);
    int p;
    int s;
    for(int i=d;i<n/2;i++)
    {
        d=n/d;
        int p=d;
        s*=p;
    }
    return s;
}
int main()
{
    int n;
    cin>>n;
    int a;
    int c=0;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        int b=divide(a)*a;
        int c=b/2;
    }
    cout<<c<<endl;
    return 0;
}
