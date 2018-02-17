#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stdio.h>
#define X first
#define Y second

#define _ << " " <<
#define debug(x) #x << " = " << x

#define ll long long
#define ull unsigned long long

using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

const ll mod = 1000000000000000003;

ll mul(ll a, ll b)
{
    ll r = 0;
    for (int i = 62; i >= 0; i--)
    {
        if (b & (1ll << i))
        {
            r = (r * 2 + a) % mod;
        } else
        {
            r = (r * 2) % mod;
        }
    }

    return r;
}

ll inv(ll x)
{
    const ll pow = mod - 2;
    ll r = 1;

    for (int i = 62; i >= 0; i--)
    {
        r = mul(r, r);
        if (pow & (1ll << i))
        {
            r = mul(r, x);
        }
    }

    return r;
}

ll choose(ll n, ll k)
{
    //std::cout << debug(n) _ debug(k) << std::endl;
    ll n1 = 1;
    for (int i = 2; i <= n; i++) n1 = mul(n1, i);

    ll n2 = 1;
    for (int i = 2; i <= k; i++) n2 = mul(n2, i);
    for (int i = 2; i <= n - k; i++) n2 = mul(n2, i);

    n2 = inv(n2);
    ll r = mul(n1, n2);
    //std::cout << debug(r) << std::endl;
    return r;
}

ll inf;

ll fnum(int len, ll max, int cz)
{
   // std::cout << debug(len) _ debug(max) _ debug(cz) << std::endl;
    if (cz < 0 || len < cz) return 0;

    if (len == 0)
        return cz == 0;

    ll mask = (1ll << len) - 1;
    if ((mask & max) == mask)
    {
        return choose(len, cz);
    }

    if (max & (1ll << (len - 1)))
    {
        return fnum(len - 1, inf, cz - 1) + fnum(len - 1, max, cz);
    } else
    {
        return fnum(len - 1, max, cz - 1);
    }
}

int main()
{
    for (int i = 0;i < 62; i++) inf |= (1ll << i);

    std::ios::sync_with_stdio(false);

    ll s, t, z;
    std::cin >> s >> t >> z;

    ll ls = 63 - __builtin_clzll(s);
    ll lt = 63 - __builtin_clzll(t);

    if (lt == ls)
    {
        ll ans = 0;
        ans += fnum(lt, t, z);
        //std::cout << debug(ans) << std::endl;

        if (__builtin_popcountll(s) > 1)
        {
            ans -= fnum(ls, s - 1, z);
        }

        std::cout << ans << std::endl;
        return 0;
    }

    ll ans = 0;

    for (int i = ls + 1; i < lt; i++)
    {
        ans += fnum(i, inf, z);
    //    std::cout << debug(ans) _ debug(i) << std::endl;
    }

    ans += fnum(lt, t, z);
    //std::cout << debug(ans) << std::endl;

    ans += fnum(ls, inf, z);
    if (__builtin_popcountll(s) > 1)
    {
        ans -= fnum(ls, s - 1, z);
    }

    std::cout << ans << std::endl;

    return 0;
}
