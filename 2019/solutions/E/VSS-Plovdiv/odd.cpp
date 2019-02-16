#include<iostream>
using namespace std;
int main()
{
long long a,b,br=0,brch=0;
cin>>a>>b;
for(int ch=a;ch<=b;ch++)
{
for(int del=1;del<=ch;del++)
if(ch%del==0) br++;
if(br%2==1) brch=brch+1;
}
 cout<<brch<<endl;
return 0;
}
