/// slow?
#include <bits/stdc++.h>
#define MAXN 100001
#define endl '\n'
using namespace std;
int n;
int arr[MAXN];
int dp[MAXN][2]; /// 0 -> | <- 1
pair <int, int> best[MAXN][2];

pair <int, int> maxx(pair <int, int> x, pair <int, int> y)
{
    if (x.first >= y.first)
        return x;
    return y;
}

void input()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void init()
{
    dp[0][0] = 1;
    best[0][0] = make_pair(1, 0);
    int max1;

    for (int i = 1; i < n; i++)
    {
        max1 = 0;

        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i])
                max1 = max(max1, dp[j][0]);

        dp[i][0] = max1 + 1;
        best[i][0] = maxx(best[i - 1][0], make_pair(dp[i][0], i));
    }

    dp[n - 1][1] = 1;
    best[n - 1][1] = make_pair(1, n - 1);

    for (int i = n - 2; i >= 0; i--)
    {
        max1 = 0;

        for (int j = n - 1; j > i; j--)
            if (arr[j] < arr[i])
                max1 = max(max1, dp[j][1]);

        dp[i][1] = max1 + 1;
        best[i][1] = maxx(best[i + 1][1], make_pair(dp[i][1], i));
    }

    max1 = max(best[n - 1][0].first, best[0][1].first);

    for (int i = 1; i < n - 1; i++)
    {
        int curr;
        curr = dp[i][0] + best[i + 1][1].first;

        if (arr[i] > arr[best[i + 1][1].second])
            max1 = max(max1, curr);

        curr = dp[i][1] + best[i - 1][0].first;

        if (arr[i] > arr[best[i - 1][0].second])
            max1 = max(max1, curr);
    }

    cout << max1 << endl;
}

/**
4
2 1 5 3
3

3
1 5 5
2

7
1 2 3 1 3 2 1
6

*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    input();
    init();

    return 0;
}
