#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;
const int maxu = 63;

int n, u, a[maxn];
void read()
{
    cin >> n >> u;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

long long c[maxu][maxu];
bool is[maxu], used[maxu];
int idx[maxu], value[maxu];
int sz;
long long find_all()
{
    long long ans = 1;
    for (int i = 1; i <= sz; i++)
        if (!value[i])
    {
        int j;
        for (j = i; j <= sz; j++)
            if (value[j])
            {
                j--;
                break;
            }

        j = min(j, sz);
        int low, high;
        if (i > 1)
            low = value[i-1];
        else
            low = 0;

        if (j < sz)
            high = value[j+1];
        else
            high = u+1;

        ans *= c[high-low-1][j-i+1];

        i = j;
    }

    return ans;
}

void solve()
{
    c[0][0] = 1;
    for (int i = 1; i <= u; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = c[i-1][j-1] + c[i-1][j];
    }

    for (int i = 1; i <= n; i++)
        is[a[i]] = true;

    int curr_idx = 0;
    for (int i = 1; i <= u; i++)
    if (is[i])
    idx[i] = ++curr_idx;

    vector <int> v;
    for (int i = 1; i <= n; i++)
        if (!used[idx[a[i]]])
        used[idx[a[i]]] = true, v.push_back(idx[a[i]]);

    sz = v.size();
    long long k = (find_all() + 1) / 2;
    for (auto i: v)
    {
        long long sum = 0;
        int left = 0, right = u+1;
        for (int j = i-1; j >= 1; j--)
            if (value[j])
        {
            left = value[j];
            break;
        }

        for (int j = i+1; j <= sz; j++)
            if (value[j])
        {
            right = value[j];
            break;
        }

        for (int j = left+1; j <= right-1; j++)
        {
            value[i] = j;
            long long nxt_sum = sum + find_all();
            if (nxt_sum >= k)
            {
                k -= sum;
                break;
            }

            sum = nxt_sum;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << value[idx[a[i]]] << " ";

    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    read();
    solve();
}

