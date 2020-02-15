#include <bits/stdc++.h>
using namespace std;

typedef long long Int;

const int N=(2e5)+5;
const int L=(2e6)+5;

int type,k,n,m;
Int a[N],b[N];
Int occa[L],occb[L];
bool visa[L],visb[L];

void Solve2()
{
 Int i,j,cnt,ans;

  for(i=1;i<=n;i++)
  {
    if(visa[i])
     continue;

   visa[i]=true;
   j=i+1;
   cnt=1;
    while(j<=n && a[j]==a[i])
    {
     visa[j]=true;
     cnt++;
     j++;
    }

    if(cnt>=k)
     occa[a[i]]+=cnt-k+1;
  }

  for(i=1;i<=m;i++)
  {
    if(visb[i])
     continue;

   visb[i]=true;
   j=i+1;
   cnt=1;
    while(j<=m && b[j]==b[i])
    {
     visb[j]=true;
     cnt++;
     j++;
    }

    if(cnt>=k)
     occb[b[i]]+=cnt-k+1;
  }

 ans=0;
  for(i=0;i<L;i++)
   ans+=occa[i]*occb[i];

 cout<<ans<<"\n";
}

vector <int> pos[L];
bool used[N];

void Solve1()
{
 int i,j,z,limit,ind,beg;
 bool fl,valid;
 Int ans;

  for(i=1;i<=m;i++)
   pos[b[i]].push_back(i);

 ans=0;
  for(i=1;i<=n-k+1;i++)
  {
    if(used[i])
     continue;

   used[i]=true;
   fl=true;
    for(j=i+1;j<i+k;j++)
    {
     if(a[j]<=a[j-1])
     {
      fl=false;
      limit=j;
     }
    }

    if(!fl)
    {
      for(j=i;j<limit;j++)
       used[j]=true;

     continue;
    }

    for(j=0;j<pos[a[i]].size();j++)
    {
     valid=true;
     beg=pos[a[i]][j];
     ind=0;

      if(beg+k-1>m)
       continue;

      for(z=beg;z<beg+k;z++)
      {
        if(a[i+ind]!=b[z])
        {
         valid=false;
         break;
        }

       ind++;
      }

      if(valid)
       ans++;
    }
  }

 cout<<ans<<"\n";
}

int main()
{

ios::sync_with_stdio(false);
cin.tie(nullptr);

int i;

cin>>type>>k;

cin>>n;

 for(i=1;i<=n;i++)
  cin>>a[i];

cin>>m;

 for(i=1;i<=m;i++)
  cin>>b[i];

 if(type==2)
 {
  Solve2();
  return 0;
 }

Solve1();

return 0;
}
