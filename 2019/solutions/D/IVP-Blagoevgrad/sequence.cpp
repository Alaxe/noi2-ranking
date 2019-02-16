#include <bits/stdc++.h>
using namespace std;
int main(){
long long n,k,r,s=1,i;
cin>>n>>k;
if((k-1)/2==0)
{
    r=n+k-1;
}
else r=n+(k-1)/2;
s=1;
for(i=1;i<n;i++)
{
    s=s+i+i+1;
}
if(k==1)
{
    s=s+n-1;
}
else if((k-1)%2==0)
{
    s=s+r+r-n;
}
else
{
    s=s+n;
}
cout<<s<<endl;
return 0;
}

