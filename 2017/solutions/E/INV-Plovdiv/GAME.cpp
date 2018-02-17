#include<iostream>
using namespace std;
int main()
{
long long m,k,br=0,n,sum=0,blz=0,ch=0;
cin>>m>>k;
while(sum<=k)
{
    cin>>n;
    if(n%2==0) sum=sum+n;
    if(m-1==n || m+1==n || n>blz && n<m || n<blz && n>m) blz=n;ch=br;
br++;
}
if(br==1) ch=1;
cout<<ch<<" "<<sum<<endl;
return 0;
}
