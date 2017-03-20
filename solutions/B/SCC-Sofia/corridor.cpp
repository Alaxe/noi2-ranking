#include <iostream>
#include <vector>

using namespace std;

int A[350000000];

int main ()
{
    cin.tie (NULL);
    ios::sync_with_stdio(false);

    int w, h, n;
    cin >> w >> h >> n;

    int x, y;
    cin >> x >> y;
    for (int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (b != y)
        {
            for (int j = min (b, y); j < max (b, y); ++j)
                A[j] = max (A[j], a);
        }
        x = a;
        y = b;
    }

    //for (int i = 0; i < h; ++i)
    //    cout << A[i] << '\n';
    //cout << "---\n";

    int res = 0;
    for (int i = 0; i < h; ++i)
    {
        res += w - A[i];
        //cout << w - A[i] << '\n';
    }

    cout << res << '\n';
    return 0;
}
