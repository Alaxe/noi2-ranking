#include <bits/stdc++.h>
using namespace std;

typedef long long Int;

const int N=(1e5)+5;
const int L=(1e4)+5;

Int a[N],b[N];
Int ans[N],mn[N];

int main()
{

ios::sync_with_stdio(false);
cin.tie(nullptr);

Int n,i,j,res;
bool sorted;

cin>>n;

 for(i=1;i<=n;i++)
 {
  cin>>a[i];
  b[i]=a[i];
 }

sorted=true;
 for(i=2;i<=n;i++)
 {
  if(a[i]<a[i-1])
  {
   sorted=false;
   break;
  }
 }

 if(sorted)
 {
  cout<<0<<"\n";
  return 0;
 }

 for(i=2;i<=n;i++)
 {
   if(b[i]<b[i-1])
   {
    res=b[i-1]-b[i];
    b[i]=b[i-1];
    break;
   }
 }

sorted=true;
 for(i=2;i<=n;i++)
 {
  if(b[i]<b[i-1])
  {
   sorted=false;
   break;
  }
 }

 if(sorted)
 {
  cout<<res<<"\n";
  return 0;
 }

 for(i=1;i<=n;i++)
 {
   for(j=0;j<L;j++)
    ans[j]=abs(j-a[i])+mn[j];

  mn[0]=ans[0];
   for(j=1;j<L;j++)
    mn[j]=min(mn[j-1],ans[j]);
 }

cout<<mn[L-1]<<"\n";

return 0;
}
