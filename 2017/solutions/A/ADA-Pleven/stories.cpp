#include <cstdio>
#include <deque>
using namespace std;
long long n, k, ans;
long long f, mul, add, mod;
deque< pair<int, int> > d;
    // first -> value
    // second -> day
int main ()
{
    scanf("%lld%lld", &n, &k);
    scanf("%lld%lld%lld%lld", &f, &mul, &add, &mod);

    for (int i = 0; i < n; i++)
    {
        // push f
        while (!d.empty())
        {
            if (d.back().first < f)
                d.pop_back();
            else
                break;
        }
        d.push_back(make_pair(f, i));

        // get current story
        while (d.front().second + k <= i)
            d.pop_front();
        ans += d.front().first;

        // make new f
        f = (f * mul + add) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}
