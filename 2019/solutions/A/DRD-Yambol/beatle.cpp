#include <iostream>
#include <algorithm>
using namespace std;

const int N=(2e5)+5;

struct Line
{
 int y;
 int l;
 int r;
};

Line a[N];

bool Compare(Line p,Line q)
{
 return p.y<q.y;
}

struct Node
{
 int value;
 int lazy;
};

Node tree[5*N];

void Refresh(int node,int low,int high)
{
  if(tree[node].lazy==0)
   return;

  if(low!=high)
  {
   tree[node*2].lazy=tree[node].lazy;
   tree[node*2+1].lazy=tree[node].lazy;
  }

 tree[node].value=tree[node].lazy;
 tree[node].lazy=0;
}

int Query(int node,int low,int high,int ind)
{
 int mid;

 Refresh(node,low,high);

  if(low==high)
   return tree[node].value;

 mid=(low+high)/2;

  if(ind<=mid)
   return Query(node*2,low,mid,ind);
  else
   return Query(node*2+1,mid+1,high,ind);
}

void Update(int node,int low,int high,int l,int r,int val)
{
 int mid;

 Refresh(node,low,high);

  if(low>r || high<l)
   return;

  if(low>=l && high<=r)
  {
   tree[node].value=val;
   tree[node].lazy=val;
   return;
  }

 mid=(low+high)/2;
 Update(node*2,low,mid,l,r,val);
 Update(node*2+1,mid+1,high,l,r,val);
 tree[node].value=max(tree[node*2].value,tree[node*2+1].value);
}

int main()
{

ios::sync_with_stdio(false);
cin.tie(nullptr);

int n,i,x,y,d,temp,ans,t;

cin>>n;

 for(i=1;i<=n;i++)
 {
  cin>>x>>y>>d;
  a[i].y=y;
  a[i].l=x+1;
  a[i].r=x+d;
 }

sort(a+1,a+n+1,Compare);

 for(i=1;i<=n;i++)
 {
  temp=min(Query(1,1,N,a[i].l-1),Query(1,1,N,a[i].r+1));
  Update(1,1,N,a[i].l,a[i].r,temp+1);
 }

cin>>t;

 for(i=1;i<=t;i++)
 {
  cin>>x;
  ans=Query(1,1,N,x+1);
  cout<<ans<<" ";
 }

cout<<"\n";

return 0;
}
