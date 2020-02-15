#include<iostream>
using namespace std;
int factoriel(int x)
{
int y=1;
for(int i=1;i<=x;i++)
{y*=i;
cout<<x<<endl;
}
return y;
}
int main()
{
int k,n,s,s1;
cin>>n>>k;
if(k==1||k==n)cout<<"1"<<endl;
else {
s=n-k;
s1=
s=factoriel(s);
s1=factoriel(s1);
cout<<s<<" "<<s1<<endl;
cout<<s+s1<<endl;
}
return 0;
}
: ^)
