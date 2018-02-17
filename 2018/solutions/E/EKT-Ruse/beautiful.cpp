#include<iostream>
using namespace std;
int main ()
{
long long n,k,m=1,i,h;
cin>>n>>k;
for(i=1;i<n;i++)
m=m*10;
for(h=m;h<=m*9;h++)
if(h%k==0) break;
if(h%k!=0) cout<<"NO"<<endl;
else cout<<h<<endl;
return 0;
}
