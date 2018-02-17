#include<iostream>
using namespace std;
int main()
{
int m,k;
cin>>m>>k;
int min,a,b,chbdm,s=0;
int mq=1;
cin>>a;
if(a%2==0) s=s+a;
if(a>m){min=a-m;chbdm=1;}
else if(a<m){min=m-a;chbdm=1;}
else if(a==m) {min=0;chbdm=1;}
b=a;
while(s<=k)
{
cin>>a;
mq++;
if(a%2==0) s=s+a;
if(a>m && a-m<=min) {min=a-m;chbdm=mq;}
else if(a<m && m-a<=min) {min=m-a;chbdm=mq;}
b=a;
}
cout<<chbdm<<" "<<s<<endl;
return 0;
}
