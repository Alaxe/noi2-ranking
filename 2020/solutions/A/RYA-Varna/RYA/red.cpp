#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 2, MAXK = 1e4 + 2, MAXC = 2e6 + 2;
const long long mod1 = 1e9 + 7, mod2 = 1e9 + 9;
const long long p1 = 2e6 + 3, p2 = 2e6 + 29;
int n,m,k,w;
long long a[MAXN],b[MAXN];
int cnt1[MAXC],cnt2[MAXC];
map<pair<long long,long long>,int> mp;
struct aaa
{
    long long hsh[2];
    aaa() {}
    aaa(long long a,long long b)
    {
        hsh[0] = a;
        hsh[1] = b;
    }
};
aaa h1[MAXN],h2[MAXN];
int br,br1,br2;
void hashArr1(long long p,long long mod,long long a[],int n,int ind)
{
    int i;
    br = 0;
    long long st = 1,cnt,hsh;
    for(i = 1; i <= k - 1; i++)
    {
        st *= p;
        st %= mod;
    }
    //cout << st << endl;
    hsh = a[0];
    cnt = 1;
    for(i = 1; i < n; i++)
    {
        //cout << i << " ";
        if(a[i] <= a[i-1])
        {
            cnt = 1;
            hsh = a[i];
        }
        else
        {
            cnt++;
            if(cnt <= k)
            {
                hsh = (hsh*p+a[i])%mod;
            }
            else
            {
                hsh = ((hsh - st*a[i-k])*p + a[i])%mod;
                if(hsh < 0)hsh += mod;
            }
            if(cnt >= k)
            {
                h1[br++].hsh[ind] = hsh;
            }
        }
        //cout << hsh << " " << cnt << endl;
    }
    br1 = br;
}
void hashArr2(long long p,long long mod,long long a[],int n,int ind)
{
    int i;
    br = 0;
    long long st = 1,cnt,hsh;
    for(i = 1; i <= k - 1; i++)
    {
        st *= p;
        st %= mod;
    }
    //cout << st << endl;
    hsh = a[0];
    cnt = 1;
    for(i = 1; i < n; i++)
    {
        //cout << i << " ";
        if(a[i] <= a[i-1])
        {
            cnt = 1;
            hsh = a[i];
        }
        else
        {
            cnt++;
            if(cnt <= k)
            {
                hsh = (hsh*p+a[i])%mod;
            }
            else
            {
                hsh = ((hsh - st*a[i-k])*p + a[i])%mod;
                if(hsh < 0)hsh += mod;
            }
            if(cnt >= k)
            {
                h2[br++].hsh[ind] = hsh;
            }
        }
        //cout << hsh << " " << cnt << endl;
    }
    br2 = br;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int i,j;
    cin >> w >> k;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for(i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    if(w == 2)
    {
        int cnt = 1,c = a[0];
        for(i = 1; i < n; i++)
        {
            if(a[i] == c)cnt++;
            else
            {
                if(cnt >= k)cnt1[c] += (cnt - k + 1);
                cnt = 1;
                c = a[i];
            }
        }
        if(cnt >= k)cnt1[c] += (cnt - k + 1);
        cnt = 1;
        c = b[0];
        for(i = 1; i < m; i++)
        {
            if(b[i] == c)cnt++;
            else
            {
                if(cnt >= k)cnt2[c] += (cnt - k + 1);
                cnt = 1;
                c = b[i];
            }
        }
        if(cnt >= k)cnt2[c] += (cnt - k + 1);
        long long ans = 0;
        for(i = 0; i < MAXC; i++)
        {
            ans = ans + 1ll*cnt1[i]*cnt2[i];
        }
        cout << ans << endl;
    }
    else if(w == 1)
    {
        long long ans = 0;
        hashArr1(p1,mod1,a,n,0);
        hashArr1(p2,mod2,a,n,1);
        hashArr2(p1,mod1,b,m,0);
        hashArr2(p2,mod2,b,m,1);
        pair<long long,long long> tmp;
        for(i = 0; i < br1; i++)
        {
            tmp = make_pair(h1[i].hsh[0],h1[i].hsh[1]);
            mp[tmp]++;
        }
        for(i = 0; i < br2; i++)
        {
            tmp = make_pair(h2[i].hsh[0],h2[i].hsh[1]);
            ans += mp[tmp];
        }
        cout << ans << endl;
    }
}
/**
2 3
11
3 4 4 4 4 5 6 6 6 6 7
16
3 6 6 6 4 4 4 5 6 6 6 7 7 6 6 6
------
1 2
6
3 6 1 3 6 7
6
2 1 3 4 3 6
------
1 2
6
3 6 1 3 6 7
9
2 1 3 6 4 1 3 6 7
*/
