#include <iostream>
#include <vector>

using namespace std;

vector<short int> v;

int main()
{
    int k, m, n, ans = 0;

    cin >> k >> m >> n;
    for (int i = 1; i < m; ++ i)
    {
        v.push_back(i);
        ++ ans;
    }
    int start = 0;
    for (int i = 2; i <= n; ++ i)
    {
        int sz = v.size();
        for (int i = start; i < sz; ++ i)
        {
            if (v[i] + k < m && v[i] - k >= 1)
            {
                v.push_back(v[i] + k);
                v.push_back(v[i] - k);
                ++ ans;
            }
            if (v[i] + k >= m && v[i] - k >= 1)
            {
                v.push_back(v[i] - k);
            }
            if (v[i] + k < m && v[i] - k < 1)
            {
                v.push_back(v[i] + k);
            }
        }
        start = sz;
    }
    cout << ans << endl;
    return 0;
}
