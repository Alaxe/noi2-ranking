#include<iostream>
using namespace std;
int s,sek,a,b,c,d,ost,a1[8];
long long k;
void read()
{
    cin>>s>>k;
    cin>>a>>b>>c>>d;
}
void fillsector(int n)
{
    int ta,tb,tc;
    n=n-((n/4)*4);
    if(n==1)
    {
        ta=a;
        tb=c;
        tc=b;
    }
    if(n==2)
    {
        ta=b;
        tb=a;
        tc=c;
    }
    if(n==3)
    {
        ta=b;
        tb=c;
        tc=a;
    }
    if(n==0)
    {
        ta=c;
        tb=a;
        tc=b;
    }
    int f=0;
    while(k)
    {
        if(f==0)
        {
            if(a1[f]>=ta) f=1;
        }
        else if(f==1)
        {
            if(a1[f]>=b) f=2;
            else if(a1[f]>=a && a1[f]>a1[0]) f=0;
        }
        else if(f==2)
        {
            if(a1[f]>=c) f=3;
            else if(a1[f]>=b && a1[f]>a1[1]) f=1;
        }
        else if(f==3)
        {
            if(a1[f]>a1[2]) f=2;
        }
        a1[f]++;
        k--;
    }
}
int main()
{
    read();
    sek=k/(4*d);
    ost=k%(4*d);
    if(ost==0)
    {
        cout<<d<<d<<d<<d<<endl;
        return 0;
    }
    k=ost;
    sek=sek+1;
    fillsector(sek);
    cout<<a1[0]<<".000 "<<a1[1]<<".000 "<<a1[2]<<".000 "<<a1[3]<<".000 "<<endl;
    return 0;
}
