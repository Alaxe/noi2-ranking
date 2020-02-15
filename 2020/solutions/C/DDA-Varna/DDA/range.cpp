#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m;
int a[100002];
int br[100002];
int bre[100002];
int p,fl;
vector<int>v;
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
sort(a,a+n);
br[a[0]]=1;
for(int i=1;i<n;i++)
{
    if(a[i]!=a[i-1])
    {
        br[a[i]]=i+1;
    }
    else bre[a[i]]++;
}
for(int i=1;i<=100000;i++)
{
    if(br[i]==0)br[i]=br[i-1]+bre[i-1];
}
cin>>m;
for(int i=0;i<m;i++)
{
    int b,e;
    fl=0;
    cin>>b>>e;
    {
        if(br[b]!=br[b-1])fl=1;
        v.push_back(br[e]-br[b]+bre[e]+fl);
    }
}
p=v.size();
for(int i=0;i<p;i++)
{
    cout<<v[i]<<endl;
}
}
