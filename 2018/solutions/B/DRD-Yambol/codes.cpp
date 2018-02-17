#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long Int;

const int N=(1e3)+5;
const int K=(1e4)+5;

vector <int> digits;
int num[N][K],biggest[K];
Int sum[K];

Int Abs(Int x)
{
  if(x>=0)
   return x;

 return -x;
}

int main()
{

Int n,k,a,b,i,j,z,pos,ind,rem,ans;
int d,cnt;

scanf("%lld%lld%lld%lld",&n,&k,&a,&b);

a--;
b--;

 for(i=1;i<=n;i++)
 {
  scanf("%d",&d);
  digits.push_back(d);
 }

cnt=0;
 for(i=a;i<=b;i++)
 {
  cnt++;
  pos=i;
   for(j=k;j>=2;j--)
   {
    rem=pos%n;
    pos/=n;

     if(pos%2==0)
     {
      ind=rem;
      num[cnt][j]=digits[ind];
     }
     else
     {
      ind=(n-1)-rem;
      num[cnt][j]=digits[ind];
     }

    sum[cnt]+=num[cnt][j];
   }

  num[cnt][1]=digits[pos];
  sum[cnt]+=num[cnt][1];
 }

 for(i=1;i<=cnt;i++)
  for(j=1;j<=k;j++)
  {
    if(num[i][j]<biggest[j])
     break;

    if(num[i][j]>biggest[j])
    {
     for(z=1;z<=k;z++)
      biggest[z]=num[i][z];
    }
  }

ans=0;
 for(i=2;i<=cnt;i++)
  ans=max(ans,Abs(sum[i]-sum[i-1]));

 for(i=1;i<=k;i++)
  printf("%d",biggest[i]);

printf(" ");

printf("%lld\n",ans);

return 0;
}
