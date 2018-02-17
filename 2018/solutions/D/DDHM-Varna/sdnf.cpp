#include<bits/stdc++.h>
using namespace std;
vector<long long>v;
long long n,p,i1,sum=0,vsize=1;
void umnojenie(long long x)
{
    for(long long j=0;j<vsize;j++)
    {
        v[j]*=i1;
        v[j]+=p;
        p=v[j]/10;
        v[j]%=10;
    }
    while(p)
    {
        v.push_back(p%10);
        p/=10;
        ++vsize;
    }
}
int main()
{
    scanf("%d",&n);
    v.push_back(1);
    for(long long i=2;i<=n;i++)
    {
        p=0;i1=i;
        while(i1%10==0)i1/=10;
        umnojenie(i1);
    }
    for(long long i=0;i<vsize;i++)
    {
        sum+=v[i];
    }
    printf("%d\n",sum);
return 0;
}
//90
