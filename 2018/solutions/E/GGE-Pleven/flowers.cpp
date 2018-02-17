#include<iostream>
using namespace std;
int main ()
{
    long long n,q,i,a,b=0,c=-1,d,x,y,z,Max=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a;
        if(a>=Max)
        {
            b=b+Max;
            c++;
            Max=a;
        }
        else if(a==Max)
        {
            Max=a;
        }
        else
        {
            b=b+a;
            c++;
        }
    }
    cin>>q;
    d=Max*c;
    x=d-b;
    y=x*q;
    cout<<y<<endl;
    return 0;
}
