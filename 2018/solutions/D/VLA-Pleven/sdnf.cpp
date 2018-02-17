#include<iostream>
using namespace std;
int main()
{long long i,j,n,s=1,sb=0,k;
cin>>n;
for(i=1;i<=n;i++)
{
    s=s*i;
}
k=s;
while(s>0)
{
    sb=sb+s%10;
    s=s/10;
}
cout<<sb<<endl;



return 0;
}
