#include<iostream>
#include<map>

#define int long long

using namespace std;

int k, n, m;
const int maxn = 100100;

int a[maxn], b[maxn];

bool inva[maxn];
bool invb[maxn];

const int N = 1e9+7, M = 1e9+9;
const int N2 = 73;

void solve1()
{
    cin >> k;
    cin >> n;
    int last = -1, num = 0;
    for(int i = 0; i < n; i ++)
    {
        cin >> a[i];
        a[i] += 42;

        if(a[i] <= last)
        {
            for(int j = 0; j < min(num, k - 1); j ++)
            {
                inva[i - 1 - j] = true;
            }
            num = 1;
        } else {
            num ++;
        }
        last = a[i];
    }
    for(int j = 0; j < min(num, k - 1); j ++)
    {
        inva[n - 1 - j] = true;
    }
    cin >> m;
    last = -1;
    num = 0;
    for(int i = 0; i < m; i ++)
    {
        cin >> b[i];
        b[i] += 42;

        if(b[i] <= last)
        {
            for(int j = 0; j < min(num, k - 1); j ++)
            {
                invb[i - 1 - j] = true;
            }
            num = 1;
        } else {
            num ++;
        }
        last = b[i];
    }

    for(int j = 0; j < min(num, k - 1); j ++)
    {
        invb[m - 1 - j] = true;
    }

    long long H = 1;
    long long H2 = 1;
    for(int i = 0; i < k; i ++)
    {
        H *= N;
        H %= M;
        H2 *= N2;
        H2 %= M;
    }

    map< pair<long long, long long> , long long> sa, sb;
    long long ha = 0, hb = 0;
    long long ha2 = 0, hb2 = 0;

    for(int i = 0; i < k - 1; i ++)
    {
        ha *= N;
        ha += a[i];
        ha %= M;

        ha2 *= N2;
        ha2 += a[i];
        ha2 %= M;
    }
    for(int i = k - 1; i < n; i ++)
    {
        ha *= N;
        ha += a[i];
        ha %= M;

        ha2 *= N2;
        ha2 += a[i];
        ha2 %= M;
        if(i >= k)
        {
            ha -= (H * a[i - k]) % M;
            if(ha < 0)  ha += M;
        }
        if(i >= k)
        {
            ha2 -= (H2 * a[i - k]) % M;
            if(ha2 < 0)  ha2 += M;
        }

        if(!inva[i - k + 1])
        {
            if(sa.count({ha, ha2}) == 0)   sa[{ha, ha2}] = 0;
            sa[{ha, ha2}] ++;
        }
        //cout << ">" << ha << endl;
    }

    for(int i = 0; i < k - 1; i ++)
    {
        hb *= N;
        hb += b[i];
        hb %= M;

        hb2 *= N2;
        hb2 += b[i];
        hb2 %= M;
    }
    for(int i = k - 1; i < m; i ++)
    {
        hb *= N;
        hb += b[i];
        hb %= M;

        hb2 *= N2;
        hb2 += b[i];
        hb2 %= M;
        if(i >= k)
        {
            hb -= (H * b[i - k]) % M;
            if(hb < 0)  hb += M;
        }

        if(i >= k)
        {
            hb2 -= (H2 * b[i - k]) % M;
            if(hb2 < 0)  hb2 += M;
        }
        if(!invb[i - k + 1])
        {
            if(sb.count({hb, hb2}) == 0)   sb[{hb, hb2}] = 0;
            sb[{hb, hb2}] ++;
        }
    }

    int ans = 0;
    for(auto i: sa)
    {
        //cout << i.first << endl;
        if(sb.count(i.first) != 0)
        {
            ans += i.second * sb[i.first];
        }
    }
    cout << ans;

}

const int maxa = 2000200;

int a2[maxa];
int b2[maxa];

void solve2()
{
    cin >> k;
    cin >> n;
    int last = -1, num = 1;
    for(int i = 0; i < n; i ++)
    {
        cin >> a[i];
        if(a[i] != last)
        {
            if(last != -1)
            {
                if(num - k + 1 > 0) a2[last] += num - k + 1;
            }
            num = 1;
            last = a[i];
        } else {
            num ++;
        }
    }
    if(num - k + 1 > 0) a2[last] += num - k + 1;

    cin >> m;

    last = -1;
    num = 1;
    for(int i = 0; i < m; i ++)
    {
        cin >> b[i];
        if(b[i] != last)
        {
            if(last != -1)
            {
                if(num - k + 1 > 0) b2[last] += num - k + 1;
            }
            num = 1;
            last = b[i];
        } else {
            num ++;
        }
    }
    if(num - k + 1 > 0) b2[last] += num - k + 1;
    long long ans = 0;
    for(int i = 0; i < maxa; i ++)
    {
        ans += a2[i] * b2[i];
    }
    cout << ans;
    return;
}

#undef int
int main()
#define int long long
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int w;
    cin >> w;
    if(w == 1)
    {
        solve1();
    } else {
        solve2();
    }
}
/**
2 3
11
3 4 4 4 4 5 6 6 6 6 7
16
3 6 6 6 4 4 4 5 6 6 6 7 7 6 6 6
*/
/**
1 2
6
2 1 3 4 3 6
6
3 6 1 3 6 7
*/
/**
1 3
11
3 4 4 4 4 5 6 6 6 6 7
16
3 6 6 6 4 4 4 5 6 6 6 7 7 6 6 6
*/
/**
1 3
10
1 2 3 4 1 2 3 4 5 6
7
3 4 5 7 8 9 10
*/
