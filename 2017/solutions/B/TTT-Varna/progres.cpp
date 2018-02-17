#include <cstdio>
using namespace std;
const int MOD=123456789012345;
long long dp[1001][1001], sum;
int n, num[1001];
int main ()
{
    scanf ("%lld",&n);
    for (int i=1; i<=n; i++)
    {
        scanf ("%lld",&num[i]);
        for (int j=i-1; j>0; j--)
        {
            if (num[i]-num[j]>0)
            {
                dp[num[i]-num[j]][i]+=(1+(dp[num[i]-num[j]][j]%MOD))%MOD;
                sum+=(1+(dp[num[i]-num[j]][j]%MOD))%MOD;
                sum%=MOD;
            }
        }
    }
    sum%=MOD;
    printf ("%lld\n",sum);

}
