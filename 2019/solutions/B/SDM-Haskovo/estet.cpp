#include<iostream>

using namespace std;

const int MAXN = 1e5 + 5;

int n;
int a[MAXN];

int length = 0;
bool special[MAXN];
int dp[MAXN], maxArr[MAXN], lastElement[MAXN];

void process(int x)
{
    int l, r, mid;

    if(length==0)
    {
        dp[0] = x;
        length = 1;

        return;
    }
    if(dp[length-1] < x)
    {
        dp[length] = x;
        length++;

        return;
    }
    if(dp[0]>x)
    {
        dp[0] = x;
        return;
    }
    if(length==1)
    {
        return;
    }

    l = 1;
    r = length - 1;
    while(l+1<r)
    {
        mid = (l+r)/2;

        if(dp[mid-1]<x) l = mid;
        else r = mid - 1;
    }

    if(dp[r-1]<x) dp[r] = x;
    else if(dp[l-1]<x) dp[l] = x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    srand(0);

    int answer = -1, maxLength = 0;;

    cin >> n;
    for(int i = 0;i<n;i++)
    {
        cin >> a[i];
    }

    for(int i = 0;i<=n;i++)
    {
        dp[i] = MAXN;
    }

    for(int i = 0;i<n;i++)
    {
        int lastLength = length;

        process(a[i]);
        maxArr[i] = length;
        lastElement[i] = dp[length-1];

        if(length!=lastLength)
        {
            special[i] = true;
        }
    }
    answer = length;

    for(int i = 0;i<=n;i++)
    {
        dp[i] = MAXN;
    }

    length = 0;
    for(int i = n-1;i>=0;i--)
    {
        if(special[i]==true)
        {
            if(length!=0)
            {
                //cout << i << " --> " << dp[0] << '\n';
                int l, r, mid;

                if(dp[0]<a[i])
                {
                    l = 0;
                    r = length - 1;
                    while(l+1<r)
                    {
                        mid = (l+r)/2;

                        if(dp[mid]<a[i]) l = mid;
                        else r = mid - 1;
                    }

                    //cout << l << " " << r << '\n';
                    if(dp[r]<a[i]) answer = max(answer, maxArr[i]+r+1);
                    if(dp[l]<a[i]) answer = max(answer, maxArr[i]+l+1);
                }
            }
        }
        process(a[i]);
    }
    answer = max(answer, length);

    cout << answer << '\n';
}
/*
20
38 7719 21238 2437 8855 11797 8365 32285 10450 30612 5853 28100 1142 281 20537 15921 8945 26285 2997 14680
*/
