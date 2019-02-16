#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int fac[43],maxi=0;
void nm(int a)
{
    for(int i=2; a!=1; i++)
    {
        int br=1;
        while(a%i==0)
        {
            br*=i;
            a/=i;
            if(fac[i]<br)
                fac[i]=br;
            if(i>maxi)
                maxi=i;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,b,del=1,mina=43;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        if(a<mina)
            mina=a;
        nm(a);
    }
    for(int i=0; i<=maxi; i++)
    {
        if(fac[i])
            del*=fac[i];
    }
    for(unsigned long long i=mina;; i++)
    {
        if((i*i)%del==0)
        {
            cout<<i<<endl;
            return 0;
        }
    }
}


