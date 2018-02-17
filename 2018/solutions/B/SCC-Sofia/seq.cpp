#include <iostream>
#include <map>

using namespace std;

map <pair <int, int>, long long> memo;

long long solve (int maxx, int sum)
{
    pair <int, int> newP;
    newP.first = maxx;
    newP.second = sum;

    if (memo.find(newP) != memo.end())
    {
        return memo[newP];
    }

    long long res = 0;
    for (int i = min(maxx, sum); i > 0; --i)
    {
        if (i == 1 or sum - i == 0)
        {
            ++res;
        }
        else
        {
            res += solve(i, sum - i);
        }
    }

    memo[newP] = res;
    return res;
}

int main ()
{
    int n, m; //sum, maxx
    cin >> n >> m;

    cout << solve(m, n) << '\n';

    return 0;
}
