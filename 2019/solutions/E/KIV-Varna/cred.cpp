#include<iostream>
using namespace std;
int main()
{
int n,m,br=1,slch=0,a,b;
cin>>n>>m;
a=n;
slch=a+n%10;
b=slch;
do{slch=slch+b%10;
b/=10;
br++;
if(slch>=m)cout<<br-1<<endl;}while(m>slch);
return 0;
}
