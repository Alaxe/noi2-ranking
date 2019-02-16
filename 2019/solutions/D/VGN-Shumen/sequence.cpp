#include<iostream>
using namespace std;

int main()
{
long long int n,k,br=0,in=0;
cin>>n>>k;
long long int i;
for(i=1;i<n;i++)in+=(i*2-1);
in+=(n*2-1);
br=1;
i++;
while(br<k)
{
    br+=2;
    in+=(i*2-1);
    i++;
}
i--;
if(br==k)in-=(n-1);
else
{
    in-=(i*2-1);
    in+=n;
}
cout<<in<<endl;
return 0;
}
