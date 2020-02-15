#include<iostream>
#include<fstream>
#include<random>

using namespace std;

const int MAXA = 1e4 + 5;
const int MAXN = 1e5 + 5;
const int inf = 1e9 + 5;

int n;
int a[MAXN];

int dp[2][MAXA];

int myAbs(int x)
{
    return max(x, -x);
}

bool isSorted[MAXN];
long long specialSolve()
{
    long long answer = inf;

    isSorted[n] = true;
    isSorted[n-1] = true;
    for(int i = n-2;i>=0;i--)
    {
        if(a[i]<=a[i+1])
        {
            isSorted[i] = true;
        }
        else
        {
            break;
        }
    }

    if(isSorted[0]==true)
    {
        return 0;
    }

    a[n] = MAXA;
    int last = 0;
    for(int i = 0;i<n;i++)
    {
        if(last<=a[i+1] && isSorted[i+1]==true)
        {
            answer = min(answer, 1LL*min(myAbs(a[i]-last), myAbs(a[i]-a[i+1])));
        }

        last = a[i];
        if(i!=0 && a[i-1]>a[i]) break;
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0;i<n;i++)
    {
        cin >> a[i];
    }

    if(n>15000)
    {
        cout << specialSolve() << '\n';
        return 0;
    }

    for(int i = 0;i<MAXA;i++)
    {
        dp[0][i] = myAbs(a[0]-i);
    }
    for(int i = 1;i<n;i++)
    {
        int minVal = inf, lim = min(a[i], MAXA);
        for(int j = 0;j<lim;j++)
        {
            minVal = min(minVal, dp[(i-1)&1][j]);
            dp[i&1][j] = minVal + a[i] - j;
        }
        for(int j = a[i];j<MAXA;j++)
        {
            minVal = min(minVal, dp[(i-1)&1][j]);
            dp[i&1][j] = minVal + j - a[i];
        }
    }

    int answer = inf;
    for(int j = 0;j<MAXA;j++)
    {
        answer = min(answer, dp[(n-1)&1][j]);
    }

    cout << answer << '\n';
}
/*
5
2 6 4 3 2

5
2 6 6 7 7
*/
