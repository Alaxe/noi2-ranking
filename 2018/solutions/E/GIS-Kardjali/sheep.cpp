#include<iostream>
using namespace std;
int main()
{
unsigned long long a,n,q,nom[10],max=0;
cin>>n;cin>>q;
for(int i=0;i<10;i++)
nom[i]=i;
for(int i=0;i<q;i++)
{
cin>>a;
nom[a]=11;
}
max=1;int k=1;
while(max<=n)
{
a=k;
int l=0,ost;
while(a)
{
ost=a%10;
if(nom[ost]==11||(a<10&&nom[a]==11)){l=1;break;}
a=a/10;
}
if(l==1)k++;
else {k++;max++;}
}
cout<<k-1<<endl;
return 0;
}
