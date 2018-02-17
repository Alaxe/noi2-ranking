# include <iostream>
# include <cstdio>
using namespace std;
const int k=(1<<30);
int a[10000];
int main()
{
int m,n,p,q,i;
scanf("%d%d%d%d",&m,&n,&p,&q);
q=p-q;
n=n-m;
m=0;
a[0]=1;
for(i=1;i<n+p;i++)
{
    if(i>=p)a[i]=(a[i]+a[i-p])%k;
    if(i>=q)
    {
        if(i-q+p<n)
        a[i]=(a[i]+a[i-q])%k;
      /*  else
        {
            if(a[i-q])
             cout<<i<<" "<<p<<" "<<q<<endl;
        }*/
//cout<<i<<" "<<a[i]<<" "<<a[i-p]<<" "<<a[i-q]<<endl;
}}
long long s=0;
/*for(i=0;i<n+p;i++)
{
    cout<<i<<" "<<a[i]<<endl;
}*/
for(i=n;i<n+p;i++)
{
    s=(s+a[i])%k;
   // cout<<i<<" "<<a[i]<<endl;
}

printf("%lld\n",s);
}
