#include <iostream>
using namespace std;
int main()
{
int maxbr=0,n,ba=0,bb=0,bc=0,bd=0;
cin>>n;char c[1000000];
for(int j=1;j<=n;j++)
{cin>>c[i];
for(int i=1;i<=j;i++)
{
if(c[i]=='a')ba++;
if(c[=='b')bb++;
if(c=='c')bc++;
if(c=='d')bd++;
if(ba+bb==bc+bd && maxbr<ba+bb+bc+bd)maxbr=ba+bb+bc+bd;
cout<<ba<<" "<<bb<<" "<<bc<<" "<<bd<<" "<<maxbr<<endl;
ba=0;bb=0;bc=0;bd=0;
}
cout<<maxbr;
return 0;
}
