#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
long long int n,m[10000],q,max=0,kapki=0;
cin>>n;
for(long long int i=1;i<=n;i++)
{
    cin>>m[i];
    if(m[i]>max)max=m[i];
}
cin>>q;
for(long long int j=1;j<=n;j++)
{
    if(m[j]!=max)kapki=kapki+(max-m[j])*q;
}
cout<<kapki<<endl;
return 0;
}
