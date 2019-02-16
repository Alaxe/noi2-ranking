#include <iostream>
using namespace std;

const int MAXN=100002;
const int INF=100005;

int n;
int a[MAXN];
int dp[MAXN];

int Longest_Increasing_Subsequence (int i, int prev_h)
{
    if (i==-1) return 0;
    if (dp[i]!=-1) return dp[i];
    int x;
    if (a[i]<prev_h)
        x=Longest_Increasing_Subsequence(i-1, a[i])+1; //take it = don't cut it
    else x=0;
    int y=Longest_Increasing_Subsequence(i-1, a[i+1]); //don't take it = cut it
    dp[i]=max (x, y);
    return dp[i];
}

int Longest_Decreasing_Subsequence (int i, int prev_h)
{
    if (i==-1) return 0;
    if (dp[i]!=-1) return dp[i];
    int x;
    if (a[i]>prev_h)
        x=Longest_Decreasing_Subsequence(i-1, a[i])+1; //take it = don't cut it
    else x=0;
    int y=Longest_Decreasing_Subsequence(i-1, a[i+1]); //don't take it = cut it
    dp[i]=max (x, y);
    return dp[i];
}

int main ()
{
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
        dp[i]=-1;
    }
    a[n]=INF;
    int lis=Longest_Increasing_Subsequence (n-1, INF);
    a[n]=-1;
    for (int i=0; i<n; i++)
        dp[i]=-1;
    int lds=Longest_Decreasing_Subsequence (n-1, -1);
    cout<<max (lis, lds)<<endl;
    return 0;
}
