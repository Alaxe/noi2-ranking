#include <bits/stdc++.h>
using namespace std;
long long k,m,n,br=0,i,j,rez=0,v[100]={0};
long long fun(long long a,long long br,long long nach)
{
    if (br==n){rez++;v[nach]++;return rez;}
    if (a-k>=1){fun(a-k,br+1,nach);}
    if (a+k<m){fun(a+k,br+1,nach);}
}
int main()
{

    cin>>k>>m>>n;
    if (m%2==0)
    {
        for (i=1;i<=m/2;i++)
        {
            fun(i,1,i);
        }
        rez=rez-v[m/2]/2;
    }
    else
    {
        for (i=1;i<=m/2;i++)
        {
            fun(i,1,i);
        }
    }
    cout<<rez*2<<endl;
}

