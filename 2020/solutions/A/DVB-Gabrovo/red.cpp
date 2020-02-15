#include <iostream>
#include <map>
using namespace std;

const int MAXN = 100005;
const int BASE = 2000107;
const int MOD = 1000000097;

int n, m, w, k;
int a[MAXN], b[MAXN];

map<int, int> apos, bpos;
long long bpow[MAXN], ha[MAXN], hb[MAXN];

void Init()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> w >> k;
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i];
    }
    cin >> m;
    for (int j = 1; j <= m; ++ j)
    {
        cin >> b[j];
    }
}

void Hashing()
{
    bpow[0] = 1;
    for (int i = 1; i < MAXN; ++ i)
    {
        bpow[i] = bpow[i - 1] * BASE % MOD;
    }

    for (int i = 1; i <= n; ++ i)
    {
        ha[i] = (ha[i - 1] + a[i] * bpow[i]) % MOD;
    }
    for (int i = 1; i <= m; ++ i)
    {
        hb[i] = (hb[i - 1] + b[i] * bpow[i]) % MOD;
    }
}

int getHash(int ab, int l, int r)
{
    long long h;
    if (ab == 0) h = ha[r] - ha[l - 1];
    if (ab == 1) h = hb[r] - hb[l - 1];

    if (h < 0) h += MOD;
    h = (h * bpow[max(n, m) - r]) % MOD;
    return h;
}

void FindAugment()
{
    int cnt = 0;
    for (int i = 1; i <= n; ++ i)
    {
        if (i == 1 or a[i - 1] < a[i]) cnt++;
        else cnt = 1;
        if (cnt >= k)
        {
            int h = getHash(0, i - k + 1, i);
            if (apos.count(h) == 0) apos[h] = 1;
            else apos[h]++;
        }
    }

    cnt = 0;
    for (int i = 1; i <= m; ++ i)
    {
        if (i == 1 or b[i - 1] < b[i]) cnt++;
        else cnt = 1;
        if (cnt >= k)
        {
            int h = getHash(1, i - k + 1, i);
            if (bpos.count(h) == 0) bpos[h] = 1;
            else bpos[h]++;
        }
    }
}

void FindEqual()
{
    int cnt = 0;
    for (int i = 1; i <= n; ++ i)
    {
        if (i == 1 or a[i - 1] == a[i]) cnt++;
        else cnt = 1;
        if (cnt >= k)
        {
            if (apos.count(a[i]) == 0) apos[a[i]] = 1;
            else apos[a[i]]++;
        }
    }

    cnt = 0;
    for (int i = 1; i <= m; ++ i)
    {
        if (i == 1 or b[i - 1] == b[i]) cnt++;
        else cnt = 1;
        if (cnt >= k)
        {
            if (bpos.count(b[i]) == 0) bpos[b[i]] = 1;
            else bpos[b[i]]++;
        }
    }
}

int main()
{
    Init();

    if (w == 1) Hashing();

    if (w == 1) FindAugment();
    if (w == 2) FindEqual();

    long long ans = 0;
    for (auto p : apos)
    {
        if (bpos.count(p.first) != 0)
        {
            ans += 1ll * p.second * bpos[p.first];
        }
    }

    cout << ans << endl;
    return 0;
}

/*
2 3
11
3 4 4 4 4 5 6 6 6 6 7
16
3 6 6 6 4 4 4 5 6 6 6 7 7 6 6 6
-------------------
1 2
6
2 1 3 4 3 6
6
3 6 1 3 6 7
*/
