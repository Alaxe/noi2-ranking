#include <iostream>
using namespace std;
int main(){
unsigned long long n,k,a=1,c=0,v;
cin>>n>>k;
for(int i=2;i<=n;i++)
{
a=a*10;
}
while(a%k!=0)
{
a++;
}
v=a;
while(v!=0)
{
v=v/10;
c++;
}
if(c>n)
cout<<"NO"<<endl;
else cout<<a<<endl;
return 0;
}
