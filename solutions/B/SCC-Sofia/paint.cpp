#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct square
{
    int x, y, w, h;
};

bool cmp (square a, square b)
{
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

int X, Y, N;
vector <square> input;
int res[11001];

int solve (int x)
{
    int otg = input[x].w * input[x].h;
    if (res[x] != 0)
        return res[x];

    for (int i = 0; i < N and input[i].x  < input[x].x + input[x].h; ++i)
    {
        if (input[i].x > input[x].x)
        {
            otg -= solve (i);
        }
    }
    res[x] = otg;
    return otg;
}

int main ()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> X >> Y >> N;
    for (int i = 0; i < N; ++i)
    {
        square curr;
        cin >> curr.x >> curr.y >> curr.w >> curr.h;
        input.push_back (curr);
    }

    sort (input.begin(), input.end(), cmp);

    int pole = X * Y;
    for (int i = 0; i < N; ++i)
    {
        pole -= solve (i);

    }

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        int idx;
        for (idx = 0; idx < N; ++idx)
        {
            if (input[idx].x <= a and a <= input[idx].x + input[idx].w and input[idx].y <= b and b <= input[idx].y + input[idx].h)
                break;
        }
        if (idx == N)
        {
            cout << pole << '\n';
        }
        else
        {
            for (idx = idx + 1; idx < N and input[idx].x <= a and a <= input[idx].x + input[idx].w and input[idx].y <= b and b <= input[idx].y + input[idx].h; ++idx) {}
            if (!(input[idx].x <= a and a <= input[idx].x + input[idx].w and input[idx].y <= b and b <= input[idx].y + input[idx].h))
                --idx;
            cout << res[idx] << '\n';
        }

    }

    return 0;
}
