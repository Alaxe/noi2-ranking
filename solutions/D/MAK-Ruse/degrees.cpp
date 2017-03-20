#include<iostream>
using namespace std;
int main ()
{
long long a,i,br1=0,a1,br=0,br3=0,p;
cin>>a;
a1=a;
do
{
a1=a1/10;
br1++;
}
while(a1!=0);
for(i=1;i<=br1;i++)
{
do
{
p=2*i/10;
br3++;
}
while(p!=0);
br1=br1-br3;
br3=0;
br++;
}
cout<<br<<endl;
return 0;
}