#include<iostream>
using namespace std;
int ispal(int a)
{int p1=0,p2=a;
 while(a!=0)
{
p1=p1*10+a%10;
a=a/10;}
if(p1==p2)return 1;
else return 0;
}
int main()
{
int n,rez,a,b,a1,b1,c[10];
cin>>n;
for( a=1;a<n;a++)
    for (b=1;b<a;b++)
if(ispal(a*b)==1){rez=a*b;a1=a;b1=b;}
cout<<b1<<" "<<a1<<endl<<rez;
return 0;
}
