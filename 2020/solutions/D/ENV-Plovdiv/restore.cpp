#include<bits/stdc++.h>
using namespace std;
int main()
{
long long n;
cin>>n;
long long a[n],b[n],i,j,m;
for(i=0;i<n;i++)
{
    cin>>b[i];
}

for(i=1;i<n;i++)
{
    a[i]=0;
}
m=n;
a[0]=m-b[0];
for(i=1;i<m;i++)
{
    if(b[i]==0)
    {
        a[i]=n;n--;
    }
    else
    {
        a[i]=n-b[i]-(i);
    }
}

for(j=0;j<m;j++)
{
   cout<<a[j]<<"_";
}
return 0;
}
