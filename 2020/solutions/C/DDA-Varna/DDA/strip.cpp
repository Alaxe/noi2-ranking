#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,k;
unsigned long long v[100],b[100];
unsigned long long s,r,p;
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n>>k;
if(k==1||k==n){cout<<1<<endl;return 0;}
if(k==2||k==n-1)
{
    p=max(k-1,n-k);
    cout<<p+1<<endl;
}
else
{
p=min(k-1,n-k);
r=n-p;
for(int i=1;i<=r;i++){v[i]=i;s+=i;}
for(int i=2;i<p;i++)
{
    b[r]=s;
    for(int j=r-1;j>=1;j--)
    {
        b[j]=b[j+1]-v[j+1];
    }
    for(int j=1;j<r;j++)
    {
        s+=b[j];
        v[j]=b[j];
    }
    v[r]=b[r];
}
cout<<s<<endl;
}
}
