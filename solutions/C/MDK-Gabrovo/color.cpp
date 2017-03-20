#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,x[nmax];
int SZ[nmax];
int met[nmax];
bool seen[nmax];
void query()
{
cin>>n;
memset(x,0,sizeof(x));
memset(SZ,0,sizeof(SZ));
memset(met,0,sizeof(met));
memset(seen,0,sizeof(seen));
for(int i=1;i<=n;i++)
{
cin>>x[i];
SZ[i]++;
if(i!=x[i])SZ[x[i]]++;
seen[x[i]]=1;
}
int ans=0;
for(int i=1;i<=n;i++)ans=max(ans,SZ[i]);//clearly
//Usually is the ans is calculated up to here, but not always
for(int i=1;i<=n;i++)
if(seen[i]==1&&met[i]==0)
{
int where=i,t=1;
while(met[where]==0)
{
met[where]=t;
t++;
where=x[where];
}
int dif=t-met[where];
if(dif!=1)ans=max(ans,2+dif%2);
}
cout<<ans<<endl;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
int t;
cin>>t;
for(int i=1;i<=t;i++)query();
return 0;
}
/*
2
4
4 1 2 3
5
4 1 2 3 4

1
3
3 1 2

1
5
2 3 4 5 1

1
5
2 1 4 5 3

1
5
4 1 2 2 4
*/
/*
Fails on
*/
