#include <iostream>
#include <vector>

using namespace std;

struct Duska
{
    int x;
    int y;
    int d;
};

vector<Duska> duski[100005];
int A[100005], endX, endY;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        Duska a;
        cin >> a.x >> a.y >> a.d;

        duski[a.y].push_back(a);

        if (a.x + a.d > endX)
        {
            endX = a.x + a.d;
        }
        if (a.y > endY)
        {
            endY = a.y;
        }
    }

    for (int y = 1; y <= endY; ++y) ///red
    {
        for (int i = 0; i < duski[y].size(); ++i)
        {
            //cout << "duska: " << duski[y][i].x << ' ' << duski[y][i].y << ' ' << duski[y][i].d << '\n';
            int curr = min(A[duski[y][i].x - 1], A[duski[y][i].x + duski[y][i].d]) + 1;
            for (int x = duski[y][i].x; x < duski[y][i].x + duski[y][i].d; ++x)
            {
                A[x] = curr;
            }
        }

        /*cout << "y = " << y << '\n';
        for (int i = 0; i <= endX; ++i)
        {
            cout << A[i] << ' ';
        }
        cout << '\n';*/
    }

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int a;
        cin >> a;

        cout << A[a];

        if (i < t - 1)
        {
            cout << ' ';
        }
    }
    cout << '\n';

    return 0;
}
