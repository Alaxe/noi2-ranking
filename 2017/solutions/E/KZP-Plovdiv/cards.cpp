#include <iostream>
using namespace std;
int main()
{
int n,br=0,sum=0,c=0,d=0,a,b,max=0;
cin>>n;
for(int i=0;i<n;i++)
{
cin>>a>>b;
if(a*b>c*d)
if(a==c||a==d){br++;max=br;}
if(b==c||b==d){br++;max=br;}
else br=0;
c=a;
d=b;
}
cout<<max<<endl;
return 0;
}
