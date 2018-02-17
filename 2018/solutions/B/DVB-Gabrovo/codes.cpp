#include <iostream>
#include <cmath>
#include <utility>
#include <string>
using namespace std;

const int MAXN = 128;

long long n, k, a, b;
int d[MAXN];

pair<string, int> numgen(int x)
{
    string s = "";
    int p = 0;

    long long deg = 1, idx = 0;
    while (true)
    {
        if (x / deg < n) break;
        else
        {
            deg *= n;
            idx++;
        }
    }

    for (int i = 1; i <= k - idx; ++ i)
    {
        s += (char)(d[0] + 48);
        p += d[0];
    }

    bool rev = false;
    while (deg != 0)
    {
        long long cha = x / deg;

        if (!rev)
        {
            s += (char)(d[cha] + 48);
            p += d[cha];
            if (cha % 2 != 0) rev ^= 1;
        }
        else
        {
            s += (char)(d[n - cha - 1] + 48);
            p += d[n - cha - 1];
            if ((n - cha - 1) % 2 != 0) rev ^= 1;
        }

        x = x % deg;
        deg /= n;
    }

    return make_pair(s, p);
}

string getmax(string a, string b)
{
    for (int i = 0; i < a.size(); ++ i)
    {
        if (a[i] < b[i]) return b;
        if (a[i] > b[i]) return a;
    }
}

int main()
{
    cin >> n >> k >> a >> b;
    k--;
    for (int i = 0; i < n; ++ i)
    {
        cin >> d[i];
    }

    pair<string, int> r = numgen(a - 1);
    string maxt = r.first;
    int p = r.second;
    int s = 0;
    for (int i = a + 1; i <= b; ++ i)
    {
        r = numgen(i - 1);
        maxt = getmax(maxt, r.first);
        s = max(s, (int)abs(p - r.second));
        p = r.second;
    }

    cout << maxt << ' ' << s << endl;
    return 0;
}

/*
3 2 3 5
7 1 5
*/
