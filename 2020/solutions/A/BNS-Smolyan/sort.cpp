#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
const long long INF = 1e16;

int n;
int a[MAXN];
int MX;

void read_input()
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        MX = max(MX, a[i]);
    }
}

int _abs(int f)
{
    if(f < 0) return -f;
    return f;
}

long long T[MAXN][2];

void solve()
{
    for(int i = 1; i <= MX; i++)
    {
        T[i][0] = _abs(a[0] - i);
    }
    int tp = 1;
    long long ans = INF;
    for(int i = 1; i < n; i++)
    {
        long long temp_ans = INF;
        for(int j = 1; j <= MX; j++)
        {
            temp_ans = min(temp_ans, T[j][tp ^ 1]);
            T[j][tp] = temp_ans + _abs(a[i] - j);
        }
        tp ^= 1;
    }
    for(int i = 1; i <= MX; i++)
    {
        ans = min(ans, T[i][tp ^ 1]);
    }
    printf("%lld\n", ans);
}

int main()
{
    read_input();
    solve();

    return 0;
}

/*
5
2 6 4 3 2
*/

/*
5
2 6 6 7 7
*/
