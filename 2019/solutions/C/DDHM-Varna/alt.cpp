#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<stdlib.h>
using namespace std;
long long k,m,n;
long long br[50][50];
int main()
{
    scanf("%lld%lld%lld",&k,&m,&n);
    if(m==1)
    {
        printf("0\n");
        return 0;
    }
    if(n==1)
    {
        printf("%lld\n",m-1);
        return 0;
    }
    for(int i=1;i<m;i++)br[1][i]=1;
    long long sum=0;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<m;j++)
        {
            br[i][j]=0;
            if(j-k>0)br[i][j]+=br[i-1][j-k];
            if(j+k<m)br[i][j]+=br[i-1][j+k];
            if(i==n)sum+=br[i][j];
        }
    }
    printf("%lld\n",sum);
return 0;
}
