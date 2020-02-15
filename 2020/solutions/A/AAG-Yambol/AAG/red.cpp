#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair <int, int>
using namespace std;
const int N = 1e5 + 5;
const int P = 2e6 + 3;
const pii MOD = mp(1e9 + 7, 1e9 + 9);

int w, k, n, m;
int a[N], b[N];

int pred_a[N], pred_b[N];
void calc_pred()
{
    for(int i = 2; i <= n; i++)
    {
        if(w == 1)
        {
            if(a[i] > a[i - 1])
                pred_a[i] = pred_a[i - 1] + 1;
            else
                pred_a[i] = 0;
        }
        else
        {
            if(a[i] == a[i - 1])
                pred_a[i] = pred_a[i - 1] + 1;
            else
                pred_a[i] = 0;
        }
    }

    for(int i = 2; i <= m; i++)
    {
        if(w == 1)
        {
            if(b[i] > b[i - 1])
                pred_b[i] = pred_b[i - 1] + 1;
            else
                pred_b[i] = 0;
        }
        else
        {
            if(b[i] == b[i - 1])
                pred_b[i] = pred_b[i - 1] + 1;
            else
                pred_b[i] = 0;
        }
    }
}

map <pii, int> cnt;
ll ans;

pii pw_k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> w >> k;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; i++)
        cin >> b[i];

    if(k > n || k > m)
    {
        cout << 0 << endl;
        return 0;
    }

    pw_k = mp(1, 1);
    for(int i = 1; i <= k - 1; i++)
    {
        pw_k.first = ((ll)pw_k.first * P) % MOD.first;
        pw_k.second = ((ll)pw_k.second * P) % MOD.second;
    }

    calc_pred();

    pii h = mp(0, 0);
    for(int i = 1; i <= k; i++)
    {
        h.first = (((ll)h.first * P) + a[i]) % MOD.first;
        h.second = (((ll)h.second * P) + a[i]) % MOD.second;
    }
    if(pred_a[k] >= k - 1)
        cnt[h]++;
    for(int i = k + 1; i <= n; i++)
    {
        h.first = ((ll)h.first + MOD.first - (((ll)pw_k.first * a[i - k]) % MOD.first)) % MOD.first;
        h.first = (((ll)h.first * P) + a[i]) % MOD.first;

        h.second = ((ll)h.second + MOD.second - (((ll)pw_k.second * a[i - k]) % MOD.second)) % MOD.second;
        h.second = (((ll)h.second * P) + a[i]) % MOD.second;

        if(pred_a[i] >= k - 1)
            cnt[h]++;
    }

//    for(auto it: cnt)
//    {
//        cerr << it.first.first << " " << it.first.second << " ";
//        cerr << it.second << endl;
//    }

    h = mp(0, 0);
    for(int i = 1; i <= k; i++)
    {
        h.first = (((ll)h.first * P) + b[i]) % MOD.first;
        h.second = (((ll)h.second * P) + b[i]) % MOD.second;
    }
    if(pred_b[k] >= k - 1)
        ans += cnt[h];
    for(int i = k + 1; i <= m; i++)
    {
        h.first = ((ll)h.first + MOD.first - (((ll)pw_k.first * b[i - k]) % MOD.first)) % MOD.first;
        h.first = (((ll)h.first * P) + b[i]) % MOD.first;

        h.second = ((ll)h.second + MOD.second - (((ll)pw_k.second * b[i - k]) % MOD.second)) % MOD.second;
        h.second = (((ll)h.second * P) + b[i]) % MOD.second;

        if(pred_b[i] >= k - 1)
            ans += cnt[h];
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

1 2
6
2 1 3 4 3 6
6
3 6 1 3 6 7

*/
