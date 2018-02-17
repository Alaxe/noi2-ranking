#include<iostream>
using namespace std;
int main()
{
int n,q,x,y=0,z;
cin>>n;
cin>>z;
for(int i=1;i<n;i++)
{cin>>x;
 if(x>z)y=y+(x-z);
 else y=y+(z-x);
 z=x;}
cin>>q;
cout<<q*y<<endl;
return 0;
}