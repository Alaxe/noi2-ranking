#include<iostream>
using namespace std;
int main()
{
long long int a,b,i,brd=0,br=0,ch;
cin>>a>>b;
for(ch=a;ch<=b;ch++)
{
for(i=1;i<=ch;i++)
{
if(ch%i==0)
brd++;
}
if(brd%2!=0)
br++;
}
cout<<br<<endl;
return 0;
}
