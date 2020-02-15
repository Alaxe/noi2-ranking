#include<iostream>
#include<cstdio>
using namespace std;
long long i,j,p,q,n,m,k;
long long a[101][101];
long long rek(long long l,long long r)
{
    if(r<l)return 0;
    if(a[l][r])return a[l][r];
    if(r==m || l==m)a[l][r]=1;
    else
    {
        a[l][r]=rek(l,r-1)+rek(l+1,r);
    }
    return a[l][r];
}
int main()
{
    scanf("%lld%lld",&n,&m);
    if(m==1 || m==n)
    {
        printf("1");
        return 0;
    }
    printf("%lld",rek(1,n));
    return 0;
}

