#include<iostream>
#include<cstring>
using namespace std;
long long n,t,x[100000],broi[100000],i,j,maxv;
int main()
{
cin>>t;
for(i=0;i<t;i++)
{
    cin>>n;
    for(j=1;j<=n;j++)
    {
        cin>>x[j];
        broi[x[j]]++;
        broi[j]++;
    }
    maxv=0;
    for(j=1;j<=n;j++)
    {
        maxv=max(maxv,broi[j]);
    }
    memset(broi,0,sizeof(broi));
    cout<<maxv<<endl;
}
return 0;
}