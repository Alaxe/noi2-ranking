#include <iostream>
#include <map>
#include <vector>

#define prosto 100003
#define mod 100000007

using namespace std;

int A[100000];
int B[100000];

vector<vector<int> > as, bs;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, k;
    cin >> t >> k;

    if (t == 2)
    {
        map <int, int> ak, bk;

        int n;
        cin >> n >> A[0];
        for (int i = 1, br = 1; i < n; ++i)
        {
            cin >> A[i];

            if (A[i] == A[i - 1])
            {
                ++br;

                if (i == n - 1 and br >= k)
                {
                    if (ak.find(A[i]) == ak.end())
                    {
                        ak[A[i]] = 0;
                    }

                    ak[A[i]] += br - k + 1;
                }
            }
            else
            {
                if (br >= k)
                {
                    if (ak.find(A[i - 1]) == ak.end())
                    {
                        ak[A[i - 1]] = 0;
                    }

                    ak[A[i - 1]] += br - k + 1;
                }

                br = 1;
            }
        }

        int m;
        cin >> m >> B[0];
        for (int i = 1, br = 1; i < m; ++i)
        {
            cin >> B[i];

            if (B[i] == B[i - 1])
            {
                ++br;

                if (i == n - 1 and br >= k)
                {
                    if (bk.find(B[i]) == bk.end())
                    {
                        bk[B[i]] = 0;
                    }

                    bk[B[i]] += br - k + 1;
                }
            }
            else
            {
                if (br >= k)
                {
                    if (bk.find(B[i - 1]) == bk.end())
                    {
                        bk[B[i - 1]] = 0;
                    }

                    bk[B[i - 1]] += br - k + 1;
                }

                br = 1;
            }
        }

        /*cout << "ak:\n";
        for (map<int, int>::iterator it = ak.begin(); it != ak.end(); it++)
        {
            cout << it->first << " - " << it->second <<'\n';
        }

        cout << "bk:\n";
        for (map<int, int>::iterator it = bk.begin(); it != bk.end(); it++)
        {
            cout << it->first << " - " << it->second <<'\n';
        }*/

        int res = 0;
        for (map<int, int>::iterator it = ak.begin(); it != ak.end(); it++)
        {
            if (bk.find(it->first) != bk.end())
            {
                res += it->second * bk[it->first];
            }
        }

        cout << res << '\n';

        return 0;
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i)
    {
        cin >> B[i];
    }

    if (k > m or k > n)
    {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 0; i <= n - k; ++i)
    {
        vector<int> curr;
        bool ok = true;
        for (int j = 0; j < k and ok; ++j)
        {
            if (j != 0 and A[i + j] <= A[i + j - 1])
            {
                ok = false;
            }
            else
            {
                curr.push_back(A[i + j]);
            }
        }
        if (ok)
        {
            as.push_back(curr);
        }
    }

    for (int i = 0; i <= m - k; ++i)
    {
        vector<int> curr;
        bool ok = true;
        for (int j = 0; j < k and ok; ++j)
        {
            if (j != 0 and B[i + j] <= B[i + j - 1])
            {
                ok = false;
            }
            else
            {
                curr.push_back(B[i + j]);
            }
        }
        if (ok)
        {
            bs.push_back(curr);
        }
    }

    int res = 0;
    for (int i = 0; i < as.size(); ++i)
    {
        for (int j = 0; j < bs.size(); ++j)
        {
            bool z = true;
            //cout << i << ' ' << j << as.size() << bs.size() << '\n';
            //cin >> z;
            for (int x = 0; x < as[i].size() and z; ++x)
            {
                    if (as[i][x] != bs[j][x])
                    {
                        z = false;
                    }
            }

            if (z)
            {
                res++;
            }
        }
    }

    cout << res << '\n';
    return 0;
}

