#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll brd[64];
bool b[64];
int main()
{
    ll x,n,br=0,k;
    scanf("%lld%lld",&n,&k);
    for(ll i=0;i<n;i++)
    {
        scanf("%lld",&x);
        if(b[x])continue;
        b[x]=1;
        for(ll j=2;x!=1;j++)
        {
            br=0;
            while(x%j==0)
            {
                br++;x/=j;
            }
            if(br>brd[j])brd[j]=br;
        }
    }
    ll ans=1;
    for(ll i=2;i<43;i++)
    {
        x=brd[i]/k;
        if(brd[i]%k>0)x++;
        while(x)
        {
            ans*=i;x--;
        }
    }
    printf("%lld\n",ans);
return 0;
}
