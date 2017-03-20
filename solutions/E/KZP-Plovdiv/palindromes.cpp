#include <iostream>
using namespace std;
int main()
{
int n,pal=0,maxpal=0,z,br=0,o=10,h=0,flag=0,j,q,y,ost;
cin>>n;
for(int i=1;i<=n;i++)
{
for(int k=1;k<=n;k++)
{
z=k*i;
while(z!=0)
{
ost=z%10;
z=z/10;
br++;
}
while(h!=br)
{
if(z%o==z/o){h++;o=o*10;flag=1;}
else break;
flag=0;
}
if(flag==1)j=z;
if(j>maxpal){maxpal=j;q=i;y=k;}
}
}
cout<<q<<" "<<y<<endl;
cout<<maxpal<<endl;
return 0;
}
