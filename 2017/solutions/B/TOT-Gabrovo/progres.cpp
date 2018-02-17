#include<vector>
#include<cstdio>
#define MOD 123456789012345
using namespace std;
long long dp[1005][1005],ans;
int n,a[1005],minA=2000,maxA;
vector<int> v[1005];
int main()
{
    //cin>>n;
    scanf("%d",&n);
    for (int i=0; i<n; i++)
    {
        //cin>>a[i];
        scanf("%d",&a[i]);
        minA=min(minA,a[i]);
        maxA=max(maxA,a[i]);
        v[a[i]].push_back(i);
    }
    for (int d=1; d<=maxA-minA; d++)
    {
        for (int i=1; i<n; i++)
        {
            if (a[i]-d<0)
                continue;
            for (int j=0; j<v[a[i]-d].size(); j++)
            {
                int pos=v[a[i]-d][j];
                if (pos>i)
                    break;
                dp[d][i]=(long long)(dp[d][i]+dp[d][pos]+1)%MOD;
            }
            ans=(ans+dp[d][i])%MOD;
        }
    }
    //cout<<ans<<'\n';
    printf("%lld\n",ans);
    return 0;
}
