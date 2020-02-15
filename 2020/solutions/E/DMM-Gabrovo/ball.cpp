# include <iostream>
using namespace std;

int main()
{
long long n,x;
cin>>n;
cin>>x;
if(n%2>0 and x==1) cout<<0<<endl;
if(n%2>0 and x==0) cout<<1<<endl;

if(n%2==0 and x==1) cout<<2<<endl;
if(n%2==0 and x==2) cout<<1<<endl;
return 0;
}
