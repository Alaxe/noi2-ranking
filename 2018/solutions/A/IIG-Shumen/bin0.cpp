#include <iostream>
#include <cstdio>
using namespace std;
long long s, t, z;
bool sbin[64], tbin[64];
long long szs, szt;
long long komb(long long el, long long kl)
{
    if(kl == 0LL)   return 1LL;
    if(el == kl)   return 1LL;
    if(el < kl)   return 0LL;
    long long p = el - kl, ret = 1LL;
    if(p > kl)
    {
        for(long long i = el; i > p; -- i)
        {
            ret *= i;
            if(kl == 1LL)   continue;
            if(ret % kl == 0)
            {
                ret /= kl;
                -- kl;
            }
        }
        while(kl > 1LL)
        {
            ret /= kl;
            -- kl;
        }
    }
    else
    {
        for(long long i = el; i > kl; -- i)
        {
            ret *= i;
            if(p == 1LL)   continue;
            if(ret % p == 0)
            {
                ret /= p;
                -- p;
            }
        }
        while(p > 1LL)
        {
            ret /= p;
            -- p;
        }
    }
    return ret;
}
void solve()
{
    long long anss = 0LL, anst = 0LL, br0 = 0LL;
    if(z == 0LL)
    {
        anss = szs - 1LL;
        anst = szt - 1LL;
        bool l = false;
        for(long long i = szs - 1LL; i >= 0LL; -- i)
        {
            if(sbin[i] == 0)
            {
                 l = true;
                 break;
            }
        }
        if(l == false)   ++ anss;
        l = false;
        for(long long i = szt - 1LL; i >= 0LL; -- i)
        {
            if(tbin[i] == 0)
            {
                l = true;
                break;
            }
        }
        if(l == false)   ++ anst;
        long long ans = anst - anss;
        cout << ans << "\n";
        return;
    }
    for(long long i = szs - 2LL; i >= z; -- i)   anss += komb(i, z);
    for(long long i = szs - 2LL; i >= 0LL; -- i)
    {
        if(sbin[i] == 0)
        {
            ++ br0;
            if(br0 == z)
            {
                bool l = false;
                for(long long j = i - 1; j >= 0LL; -- j)
                {
                    if(sbin[j] == 0)
                    {
                        l = true;
                        break;
                    }
                }
                if(l == false)   ++ anss;
                break;
            }
        }
        else   anss += komb(i, z - br0 - 1LL);
    }
    br0 = 0LL;
    for(long long i = szt - 2LL; i >= z; -- i)   anst += komb(i, z);
    for(long long i = szt - 2LL; i >= 0LL; -- i)
    {
        if(tbin[i] == 0)
        {
            ++ br0;
            if(br0 == z)
            {
                bool l = false;
                for(long long j = i - 1; j >= 0LL; -- j)
                {
                    if(tbin[j] == 0)
                    {
                        l = true;
                        break;
                    }
                }
                if(l == false)   ++ anst;
                break;
            }
        }
        else   anst += komb(i, z - br0 - 1LL);
    }
    long long ans = anst - anss;
    cout << ans << "\n";
}
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> t >> z;
    -- s;
    while(s)
    {
        sbin[szs] = s % 2LL;
        ++ szs;
        s /= 2LL;
    }
    while(t)
    {
        tbin[szt] = t % 2LL;
        ++ szt;
        t /= 2LL;
    }
    solve();
    return 0;
}