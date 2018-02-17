#include<iostream>
using namespace std;
int main()
{
int N,i,L,a[3],t;
cin>>N;
cin>>L;
t=N;
for(i=0;i<L;i++)
{
cin>>a[i];
if(t/10==a[i])t+=11;
if(t%10==a[i]&&(t+1)%10!=a[i])t++;
}
cout<<t<<endl;
}
