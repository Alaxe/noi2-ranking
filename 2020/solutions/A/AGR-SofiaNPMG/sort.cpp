#include<iostream>
#include<set>
#include<vector>

#define int long long

using namespace std;

const int maxn = 100100;
int n;

int a[maxn];
int dp[2][maxn];

set<int> diff;
int psize;
int p[maxn];
int mn[maxn];

#undef int
int main()
#define int long long
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> a[i];
        diff.insert(a[i]);
    }
    for(auto i: diff)
    {
        p[psize++] = i;
    }
    for(int j = 0; j < psize; j ++)
    {
        dp[0][j] = abs(a[0] - p[j]);
    }


    for(int i = 1; i < n; i ++)
    {
        for(int j = 0; j < psize; j ++)
        {
            if(j == 0)
            {
                mn[j] = dp[(i - 1) % 2][j];
            } else {
                mn[j] = min(mn[j - 1], dp[(i - 1) % 2][j]);
            }
        }
        for(int j = 0; j < psize; j ++)
        {
            dp[(i) % 2][j] = mn[j] + abs(a[i] - p[j]);
        }
    }
    /*for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < psize; j ++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    int ans = -1;
    for(int i = 0; i < psize; i ++)
    {
        if(ans == -1 || ans > dp[(n - 1) % 2][i])
        {
            ans = dp[(n - 1) % 2][i];
        }
    }
    cout << ans;
}
/**
5
2 6 4 3 2
*/
/**
6
1 2 3 1 2 3
*/
/**
5
2 6 6 7 7
*/
