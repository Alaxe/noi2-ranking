#include<iostream>
#include<cstdio>
#define INF 100000
using namespace std;
int b[100006];
int i,j,p,q,n,m,max1,min1=999999;
int rsq(int k)
{
    int sum=0;
    while(k>=0)
    {
        sum+=b[k];
        k=(k&(k+1))-1;
    }
    return sum;
}
void update(int k)
{
    while(k<=INF)
    {
        b[k]++;
        k=k|(k+1);
    }
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&p);
        if(p>max1)max1=p;
        if(p<min1)min1=p;
        update(p);
    }
    cin>>m;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&p,&q);
        if(q<min1 || p>max1)
        {
            printf("0\n");
            continue;
        }
        printf("%d\n",rsq(q)-rsq(p-1));
    }
    return 0;
}

