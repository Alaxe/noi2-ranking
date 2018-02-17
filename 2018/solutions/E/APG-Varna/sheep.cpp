#include<iostream>
using namespace std;
int brc(int n,int a,int b,int c)
{
    bool t;
    while(n!=0)
    {
        if(n%10==a||n%10==b||n%10==c)
        {
            t=0;
            break;
        }
        else t=1;
        n/=10;
    }
    return t;
}
int main()
{
    int n,l,b,c,a;
    unsigned long long imax=0,br=0;
    cin>>n>>l;
    if(l>0)
    {
        cin>>a;
        l--;
    }
    if(l>0)
    {
        cin>>b;
        l--;
    }
    if(l>0)cin>>c;
    for(long long i=0; br<n; i++)
    {
        if(brc(i,a,b,c)==1)
        {
            if(i>imax)imax=i;
            br++;
        }

    }
cout<<imax<<endl;
}
