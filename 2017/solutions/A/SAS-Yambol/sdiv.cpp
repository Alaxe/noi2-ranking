#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
#include <climits>
using namespace std;
typedef long long lld;

char seq[10002];
lld m;
int n;

lld dp[10002][1002]; /// dp[i][rem] 1~i kolko davat rem
int sz;
int dig[10002];

int main ()
{
    scanf("%s", seq);
    sz = strlen(seq);

    scanf("%d %lld", &n, &m);

    for (int i=0; i<sz; i++)
    {
        dig[i+1] = (seq[i]-'0');
        /// if (dig[i+1] >= n) dig[i+1] %= n; CHECK THAT
    }

    dp[sz+1][0] = 1;
    for (int i=sz; i>=1; i--)
    {
        for (int currem=0; currem<n; currem++)
        {
            int other = currem*10 + dig[i];
            if (other >= n) other %= n;

            dp[i][currem] = dp[i+1][currem] + dp[i+1][other];
            if (dp[i][currem] >= m) dp[i][currem] -= m;
        }
    }

    lld ans = dp[1][0];
    ans--;
    if (ans < 0) ans += m;

    printf("%lld\n", ans);
}
