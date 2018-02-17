#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
    Point(){}
    Point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};

bool cmpX(Point& a, Point& b)
{
    return a.x < b.x;
}

bool cmpY(Point& a, Point& b)
{
    return a.y < b.y;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, tempX, tempY, ansX(1), ansY(1);
    cin >> n;

    Point arr[n];
    for (i = 0; i < n; ++i)
    {
        cin >> tempX >> tempY;
        arr[i] = Point(tempX, tempY);
    }

    sort(arr, arr + n, cmpX);

    int diffX(0), diffY(0);
    bool flag = false;
    for (i = 0; i < (n-1); ++i)
    {
        if ((arr[i].x != arr[i+1].x) && (arr[i].y != arr[i+1].y))
        {
            if (flag == false)
            {
                diffX = abs(arr[i+1].x) - abs(arr[i].x);
                flag = true;
            }

            if ( (flag == true) && ( (abs(diffX) == abs((arr[i+1].x - arr[i].x)))) )
                ++ansX;
        }

    }
/*******************************************************************/
    sort(arr, arr + n, cmpY);

    flag = false;
    for (i = 0; i < (n-1); ++i)
    {
        if ((arr[i].x != arr[i+1].x) && (arr[i].y != arr[i+1].y))
        {
            if (flag == false)
            {
                diffY = abs(arr[i+1].y) - abs(arr[i].y);
                flag = true;
            }

            if ( (flag == true) && ( (abs(diffY) == abs((arr[i+1].y - arr[i].y)))) )
                  ++ansY;
        }
    }
    cout << max(ansX, ansY) << '\n';
    return 0;
}
/**

6
0 0
2 1
-2 -1
-2 -2
6 3
-2 3

4
-1 1
-2 2
-3 3
-4 4

*/
/// cout << arr[i].x << ' ' << arr[i].y << "    " << arr[i+1].x << ' ' << arr[i+1].y << '\n';
/// cout << "\n\n" << ansX << ' ' << ansY;
