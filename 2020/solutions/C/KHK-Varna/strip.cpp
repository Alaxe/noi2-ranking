#include<iostream>
using namespace std;
int main()
{
int n,k;
cin>>n>>k;
if(n==1||n==2||k==1){cout<<1<<endl;return 0;}
n-=3;
k-=2;
int br=2;
if(k==n-k)br+=k*4;
else if(k<n-k)br+=k*4+(n-k-k);
else br+=(n-k)*4+(k-(n-k));
cout<<br<<endl;
}
