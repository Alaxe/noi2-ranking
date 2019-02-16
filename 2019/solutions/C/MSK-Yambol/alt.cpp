#include <iostream>
#include <algorithm>
using namespace std;
long long a[5001];
long long x=1,br=0,br1=0;
long long i=0,j=1,t=0;
long long k,m,n;

void rel1(int p, int k)
{

    long long m;
    while(br<n)
    {
     if((p+k)<m) {p=p+k;br++;}
     else {p=p-k;br++;}
    }
    br1++;
}

void rel2(int p, int k)
{
    long long m;
    while(br<n)
    {
     if((p-k)<m&&(p-k)>0) {p=p-k;br++;}
     else {p=p+k;br++;}
    }
    br1++;
}
int main()
{

    cin>>k>>m>>n;

    for(i=1;i<=m-1;i++)
    {
        a[x]=i;
        rel1(a[x], k);br=0;
        rel2(a[x], k);br=0;
        for(j=0;j<n;j++)
        {
            a[j]=0;
        }

    }
    cout<<br1;
    return 0;
}
