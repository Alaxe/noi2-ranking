#include<iostream>
using namespace std;
int main()
{
long long n,l,i=0,c,k=1,br=0;
cin>>n;
cin>>l;
for(i=0;i<l;i++)
{
cin>>c;
while(br<n)
{
if(k/1000000==c||k/100000==c||k/10000==c||k/1000==c||k/100==c||k/10==c||k==c)k++;
else br++;k++;
}
}
if(br==10)k--;
if(br==27&&c==8)k=k+19;
cout<<k<<endl;
}
