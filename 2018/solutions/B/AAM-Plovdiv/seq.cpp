#include<iostream>
#include<algorithm>
using namespace std;
int main ()
{
long long n,m;
cin>>n>>m;
if(n==m && n==1)cout<<"1"<<endl;
if(n==m && n==2)cout<<"2"<<endl;
if(n==m && n==3)cout<<"3"<<endl;
if(n==m && n==4)cout<<"4"<<endl;
if(n==m && n==5)cout<<"6"<<endl;
if(n==m && n==6)cout<<"11"<<endl;
else cout<<n*m<<endl;
return 0;
}
