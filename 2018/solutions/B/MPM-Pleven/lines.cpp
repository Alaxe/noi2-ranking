#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;
};

int main()
{
    int n;
    cin >> n;
    Point points[n];
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        Point p;
        p.x = x;
        p.y = y;
        points[i] = p;
    }

    int c = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (points[i].x == points[j].x || points[i].y == points[j].y) {
                c++;
            }
        }
    }
    cout << c << endl;
    return 0;
}
