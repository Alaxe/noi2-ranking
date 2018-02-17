#include <iostream>
#include <vector>

using namespace std;

int n;
vector <pair <int, int> > A;

bool on1Line (pair <int, int> a, pair <int, int> b, pair <int, int> c)
{
    return ((a.first + b.first) * (a.second - b.second) + (b.first + c.first) * (b.second - c.second)
           + (c.first + a.first) * (c.second - a.second)) == 0;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        pair <int, int> curr;
        cin >> curr.first >> curr.second;
        A.push_back(curr);
    }

    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int curr = 2;
            for (int k = j + 1; k < n; ++k)
            {
              //cout << i << ' ' << j << ' ' << k << ' ' << on1Line(A[i], A[j], A[k]) << '\n';
                if (on1Line(A[i], A[j], A[k]))
                {
                    ++curr;
                }
            }
            if (curr > res)
            {
                res = curr;
            }
        }
    }

    cout << res << '\n';
    return 0;
}
