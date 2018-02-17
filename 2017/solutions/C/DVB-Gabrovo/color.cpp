#include <iostream>
using namespace std;

const int MAXN = 1048576;

int p[MAXN], n, t;

int main()
{
    cin >> t;
    while (t -- != 0)
    {
        int x, y = 0;

        cin >> n;
        for (int i = 1; i <= n; ++ i)
        {
            cin >> x;
            p[x]++;
        }
        for (int i = 1; i <= n; ++ i)
        {
            y = max(p[i] + 1, y);
            p[i] = 0 ;
        }
        cout << y << endl;
    }
    return 0;
}
