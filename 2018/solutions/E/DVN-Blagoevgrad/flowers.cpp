#include <iostream>
using namespace std;
int s[10000];
int main(){
int n,q,ma=0,k=0;
cin>>n;

for(int i=0;i<n;i++)
{
cin>>s[i];
if(s[i]>=ma)
ma=s[i];
}
cin>>q;
for(int i=0;i<n;i++)
{
k=k+(ma-s[i])*q;
}
cout<<k<<endl;




return 0;
}
