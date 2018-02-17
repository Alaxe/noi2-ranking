#include <cstdio>

using namespace std;

long long s, t, z, j, cnt, ans, from, to, pow1, pow2;

long long dp[64][64];

void solve_slow(long long S, long long T)
{
    if(S>T) return;
    for(long long i=S; i<=T; ++i)
    {
        j=i;
        cnt=0;
        while(j>0)
        {
            if(j%2LL==0) cnt++;
            j>>=1;
        }
        if(cnt==z) ans++;
    }
}

int main ()
{
    //freopen("i1.txt", "r", stdin);
    scanf("%lld %lld %lld", &s, &t, &z);
    if(t-s<=10000000)
    {
        ans=0;
        solve_slow(s, t);
        printf("%lld\n", ans);
        return 0;
    }
    if(z==0)
    {
        j=from=2;
        cnt=0;
        while(from<t)
        {
            j*=2;
            cnt++;
            from+=j;
        }
        j=from=2;
        to=0;
        while(from<s)
        {
            j*=2;
            to++;
            from+=j;
        }
        if(s==1)
        {
            ans=cnt-to+1;
            printf("%lld\n", ans);
            return 0;
        }
        s=s+1;
        while(s>1)
        {
            if(s%2==1) ans--;
            s/=2;
        }
        ans=cnt-to;
        printf("%lld\n", ans);
        return 0;
    }
    ans=0;
    j=2;
    pow1=1;
    while(j<s)
    {
        j<<=1LL;
        pow1++;
    }
    from=j;
    pow2=60;
    j=1LL<<60;
    while(j>t)
    {
        j>>=1LL;
        pow2--;
    }
    to=j;
    for(long long i=1; i<=60; ++i) dp[1][i]=i;
    for(long long zeros=2; zeros<=60; ++zeros)
    {
        for(long long i=1; i<=zeros-2; ++i) dp[zeros][i]=0;
        dp[zeros][zeros-1]=dp[zeros][zeros]=1;
        for(long long i=zeros+1; i<=60; ++i) dp[zeros][i]=dp[zeros-1][i-1]+dp[zeros][i-1];
    }
    ans=0;
    cnt=0;
    for(long long i=pow1; i<pow2; ++i)
    {
        if(dp[z][i]==1) cnt++;
        ans+=dp[z][i];
    }
    if(pow1==pow2 && pow1==z) ans=1;
    if(cnt==2) ans--;
    solve_slow(s, from-1);
    solve_slow(to+1, t);
    printf("%lld\n", ans);
    return 0;
}