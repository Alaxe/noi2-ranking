#include <iostream>
#include <cstdio>
#include <map>
#include <set>
using namespace std;

const int N=1005;
const int M=110;

double x[N],y[N];
map <double,int> mp;
map <double,int> :: iterator it;
set <double> st;
int v[N];

int main()
{

int n,i,j,ans,cnt;
double k,temp;

scanf("%d",&n);

 for(i=1;i<=n;i++)
 {
  scanf("%lf%lf",&x[i],&y[i]);

  v[(int)x[i]+M]++;

   if(x[i]!=0)
    k=y[i]/x[i];
   else
    st.insert(y[i]);

  it=mp.find(k);
   if(it==mp.end())
    mp.insert(make_pair(k,1));
   else
    (*it).second++;
 }

ans=2;
 for(i=1;i<=n;i++)
  for(j=i+1;j<=n;j++)
  {
    if(x[i]==x[j])
     continue;

   k=(y[j]-y[i])/(x[j]-x[i]);
   it=mp.find(k);

    if(it!=mp.end())
    {
     cnt=(*it).second;
     temp=y[j]-(x[j]*k);

      if(st.find(temp)!=st.end())
       cnt++;

     ans=max(ans,cnt);
    }
  }

 for(i=-M;i<=M;i++)
  ans=max(ans,v[i+M]);

printf("%d\n",ans);

return 0;
}
