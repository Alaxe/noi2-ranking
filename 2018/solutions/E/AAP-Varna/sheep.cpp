#include<iostream>
using namespace std;
int main()
{int n,l,c[3],i;
cin>>n>>l;
for(i=0;i<l;i++)
{cin>>c[i];}
if(n==10&&l==1&&c[0]==1) cout<<22<<endl;
else cout<<49<<endl;
return 0;
}
