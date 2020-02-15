#include <bits/stdc++.h>
#define MAXN 1000003
#define MAXU 61
#define endl '\n'
using namespace std;

int n, u;
int arr[MAXN];
int og[MAXN];
int val[MAXN];
int pos[MAXU];
typedef unsigned long long ll;
ll fact[MAXU];
int sum[MAXU];

void input()
{
    cin >> n >> u;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        og[i] = arr[i];
    }
}

void init()
{
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i <= u; ++i)
        fact[i] = fact[i-1] * i * 1ULL;
}

ll cmb(int x, int y)
{
    ll ret = y * 1ULL;
    for (int i = 1; i < x; ++i)
    {
        ret *= (y - i);
        ret /= i;
    }
    ret /= x;
    return ret;
}

void solve()
{
    sort (arr, arr + n);
    int cnt = 1;
    int last = arr[0];
    int ptr = 0;
    pos[last] = ptr++;
    for (int i = 1; i < n; ++i)
        if (arr[i] != last)
        {
            ++cnt;
            last = arr[i];
            pos[last] = ptr++;
            //cout << "* " << ptr << " " << last << endl;
        }
    //cout << cnt << endl;
    ll all;
    ll f = u * 1LL;
    for (ll i = 1; i < (ll)cnt; ++i)
    {
        f *= (u - i);
        f /= i;
    }
    f /= cnt;
    //cout << f << endl;
    ll idx = (f + 1) / 2;
    //cout << idx << endl;


    ll tmp = idx;
    for (int i = 0; i < cnt - 1; ++i)
    {
        //cout << tmp << endl;
        for (int x = 1; x <= u; ++x)
        {
            int p = u - x;
            ll curr = cmb(cnt - i - 1, p);
            //cout << x << " : " <<  curr << " " << tmp << endl;
            if (tmp < curr)
            {
                val[i] = x;
                break;
            }
            tmp -= curr;
        }
    }

    val[cnt-1] = tmp;

    /*for (int i = 0; i < cnt; ++i)
        cout << val[i] << " ";
    cout << endl;*/

    sum[0] = val[0];
    for (int i = 1; i < cnt; ++i)
        sum[i] = sum[i-1] + val[i];

    //cout << sum[1] << endl;

    for (int i = 0; i < n; ++i)
    {
        og[i] = sum[pos[og[i]]];
        //cout << "-- " << og[i] << endl;
    }

    cout << og[0];
    for (int i = 1; i < n; ++i)
        cout << " " << og[i];
    cout << endl;
}

/**

4 26
4 6 6 4

*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solve();


    return 0;
}
