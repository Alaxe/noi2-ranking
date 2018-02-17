# include <cstdio>
# include <cstring>
# include <vector>
# include <algorithm>

using namespace std;

const int MAX_S = 128;
char aa[MAX_S];
char bb[MAX_S];

vector <int> a;
vector <int> b;

vector <int> remove_zeroes (vector <int> x)
{
    while (x.size () && !x[x.size () - 1])
        x.pop_back ();
    return x;
}

vector <int> add (vector <int> x, vector <int> y)
{
    vector <int> z;
    int i, l = 0, sz = max (x.size (), y.size ());
    for (i = 0; i < sz; i ++)
    {
        z.push_back (0);
        z[i] += l;
        if (i < x.size ())
            z[i] += x[i];
        if (i < y.size ())
            z[i] += y[i];
        l = z[i] / 10;
        z[i] = z[i] % 10;
    }
    if (l)
        z.push_back (1);
    z = remove_zeroes (z);
    return z;
}

vector <int> sub (vector <int> x, vector <int> y)
{
    vector <int> z;
    int i, l = 0, sz = x.size ();
    for (i = 0; i < sz; i ++)
    {
        z.push_back (x[i]);
        if (i < y.size ())
            z[i] -= y[i];
        z[i] -= l;
        l = 0;
        if (z[i] < 0)
        {
            z[i] += 10;
            l = 1;
        }
    }
    z = remove_zeroes (z);
    return z;

}

vector <int> db2 (vector <int> x)
{
    int i, l = 0, f;
    for (i = x.size () - 1; i >= 0 ; i --)
    {
        f = x[i] + l * 10;
        x[i] = (f >> 1);
        l = f & 1;
    }
    x = remove_zeroes (x);
    return x;
}

vector <int> mulbydig (vector <int> x, int dig)
{
    int i, l = 0;
    for (i = 0; i < x.size (); i ++)
    {
        x[i] = x[i] * dig + l;
        l = x[i] / 10;
        x[i] = x[i] % 10;
    }
    if (l)
        x.push_back (l);
    x = remove_zeroes (x);
    return x;
}

vector <int> mul (vector <int> x, vector <int> y)
{
    int i, j;
    vector <int> xy;
    vector <int> nx;
    vector <int> crr;
    for (i = 0; i < (int) y.size (); i ++)
    {
        crr = mulbydig (x, y[i]);
        xy = add (xy, crr);
        nx.clear ();
        nx.push_back (0);
        for (j = 0; j < (int) x.size (); j ++)
            nx.push_back (x[j]);
        x = nx;
    }
    xy = remove_zeroes (xy);
    return xy;
}

bool check (vector <int> lim, vector <int> x, bool type)
{
    vector <int> y = add (mul (x, x), x);
    lim = remove_zeroes (lim);
    y = remove_zeroes (y);
    if (lim.size () < y.size ())
        return false;
    if (lim.size () > y.size ())
        return true;
    int i;
    for (i = lim.size () - 1; i >= 0; i --)
    {
        if (lim[i] < y[i])
            return false;
        if (lim[i] > y[i])
            return true;
    }
    return type;
}


vector <int> find (vector <int> x, bool type)
{
    vector <int> l;
    vector <int> r (54, 1);
    vector <int> mid, ch;
    int i;
    while (1)
    {
        ch = sub (r, l);
        if (ch.size () == 1 && ch[0] <= 1)
            break;

        mid = db2 (add (r, l));

        if (check (x, mid, type))
            l = mid;
        else
            r = mid;
    }
    l = remove_zeroes (l);
    return l;
}

int main ()
{
    ///freopen ("in3.txt", "r", stdin);
    int i;
    scanf ("%s", aa);
    scanf ("%s", bb);
    for (i = strlen (aa) - 1; i >= 0; i --)
        a.push_back (aa[i] - '0');
    for (i = strlen (bb) - 1; i >= 0; i --)
        b.push_back (bb[i] - '0');

    vector <int> ansa = find (a, 0);
    vector <int> ansb = find (b, 1);

    vector <int> ans = sub (ansb, ansa);
    ans = remove_zeroes (ans);
    if (!ans.size ())
        ans.push_back (0);
    for (i = ans.size () - 1; i >= 0; i --)
        printf ("%d", ans[i]);
    printf ("\n");
    return 0;
}
