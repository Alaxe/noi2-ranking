#include<iostream>
using namespace std;
int main()
{
int n,a1,b1,a2,b2,br=0,l=0,max=0,x;
cin>>n>>a1>>b1;if(a1<b1) {x=a1;a1=b1;b1=x;}
a2=a1;
b2=b1;
for(int i=1;i<n;i++)
{
cin>>a1>>b1;
if(a1<b1) {x=a1;a1=b1;b1=x;}
if(a1<=a2 && a2<=a1 && l==0) {l=1;br=br+2;}
if(a1<=b2 && b1<=b2 && l==1) {l=1;br=br+2;}
if(a1>b2 && b1>b2 || a1>=b2 && b1>b2 || a1>b2 && b1>=b2 && l==1) {l=0;if(br>max)max=br;br=0;}
a2=a1;
b2=b1;
}
cout<<max<<endl;
return 0;
}
