#include<iostream>
using namespace std;
int main()
{
int n,a[1000],b[1000],maxi=0,pr[10000],tz[1000];
cin>>n;
for(int i=1;i<=n;i++)
{
pr[i]=a[i]*b[i];
 while(pr[i]!=0)
 {
     tz[i]=pr[i]%10;
 }
if(tz[i]=tz[i+3]) cout<<pr<<endl;
}
return 0;
}
