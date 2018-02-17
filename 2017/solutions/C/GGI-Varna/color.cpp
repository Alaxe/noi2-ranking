#include <bits/stdc++.h>
using namespace std;

int t, n, x;
int br[100001] = {0};
int m = -1;

int main ( )
{
    cin >> t;
    for (int i = 0; i < t; ++ i)
    {
        cin >> n;
        for (int j = 0; j < n; ++ j)
        {
            cin >> x;
            br[x] ++;
            if (br[x] > m) m = br[x];
        }
        cout << m + 1 << endl;
        m = 0;
        for (int j = 0; j <= n; ++ j)
        {
            br[j] = 0;
        }
    }
    return 0;
}
