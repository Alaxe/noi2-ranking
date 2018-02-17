#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

struct point
{
    int x, y;
    point (int _x = 0, int _y = 0) : x (_x), y (_y)
    { }
};

struct line
{
    int a; int b; int c; /// 1x + by + c = 0
    line (point a, point b)
    {
        this->a = (a.y - b.y);
        this->b = (b.x - a.x);
        int gcd = __gcd (this->a, this->b);
        if (gcd != 0)
        {
            this->a /= gcd;
            this->b /= gcd;
        }
        this->c = (- this->a * a.x) - this->b * a.y;
    }

    bool operator < (const line& l) const
    {
        if (this->a == l.a)
        {
            if (this->b == l.b)
                return this->c < l.c;
            return this->b < l.b;
        }
        return this->a < l.a;
    }

    bool operator == (const line& l) const
    {
       return this->a == l.a and this->b == l.b and this->c == l.c;
    }
};

vector < point > points;
//map < line, int/*vector < int >*/ > lines;
vector < line > lines;

int main ()
{
    cin.tie (nullptr);
    ios::sync_with_stdio (false);
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; i ++)
    {
        int x, y;
        cin >> x >> y;
        points.push_back (point (x, y));
        for (int j = 0 ; j < i ; j ++)
            lines.push_back(line (points [i], points [j]));
    }
    sort (lines.begin(), lines.end ());
    int max_lines = 1, curr_lines = 1;
    for (int i = 1 ; i < lines.size () ; i ++)
    {
        if (lines [i - 1] == lines [i])
            curr_lines ++;
        else
        {
            max_lines = max (max_lines, curr_lines);
            curr_lines = 1;
        }
    }
    int max_n = (1 + sqrt (max_lines * 8 + 1)) / 2;
    cout << max_n << endl;
    return 0;
}

