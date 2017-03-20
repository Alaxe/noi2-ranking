# include <cstdio>
# include <vector>

using namespace std;

int k, n;
long long first, mul, add, mod;

vector <pair <int, int> > f, b;

long long ans;

int main ()
{
    ///freopen ("in1.txt", "r", stdin);
    int i, a, p, q;

    scanf ("%d%d", &n, &k);
    scanf ("%lld%lld%lld%lld", &first, &mul, &add, &mod);

    for (i = 1; i <= n; i ++, first = (first * mul + add) % mod)
    {
        a = first;
        if (f.size ())
            f.push_back (make_pair (max (f[f.size () - 1].first, a), a));
        else
            f.push_back (make_pair (a, a));
        if (i > k)
        {
            if (!b.size ())
            {
                b.push_back (make_pair (f[f.size () - 1].second, f[f.size () - 1].second));
                f.pop_back ();
                while (f.size ())
                {
                    b.push_back (make_pair (max (b[b.size () - 1].first, f[f.size () - 1].second), f[f.size () - 1].second));
                    f.pop_back ();
                }
            }
            b.pop_back ();
        }

        q = 0;
        if (b.size () && b[b.size () - 1].first > q)
            q = b[b.size () - 1].first;
        if (f.size () && f[f.size () - 1].first > q)
            q = f[f.size () - 1].first;
        ans += q;
    }

    printf ("%lld\n", ans);
    return 0;
}
