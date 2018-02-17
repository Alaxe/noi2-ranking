#include<iostream>
#include<string>
#include<cstdio>
#define MAX_N 1024
using namespace std;
long long int n, m;
long long int razmer, a[MAX_N];
long long int dp[MAX_N][2];
string arr;
void read()
{
    cin>>arr;
    scanf("%lld %lld", &n, &m);
}
void toarray()
{
    razmer=arr.size();
    for(int i=0; i<razmer; i++)
        a[i]=arr[i]-'0';
}
void copyy(int i)
{
    for(int j=0; j<n; j++)
        dp[j][(i+1)%2]=dp[j][i%2];
}
void solve()
{
    long long int ost=10%n;
    dp[a[0]%n][0]=dp[a[0]%n][1]=1;
    for(int i=1; i<razmer; i++)
    {
        for(int j=0; j<n; j++)
            if(dp[j][(i+1)%2])
            {
                dp[(j*ost+a[i]%n)%n][i%2]+=dp[j][(i+1)%2];
                if(dp[(j*ost+a[i]%n)%n][i%2]>=m)
                    dp[(j*ost+a[i]%n)%n][i%2]%=m;
            }
        dp[a[i]%n][i%2]++;
        if(dp[a[i]%n][i%2]>=m)
            dp[a[i]%n][i%2]%=m;
        copyy(i);
    }
    printf("%d\n", dp[0][(n+1)%2]);
}
int main()
{
    read();
    toarray();
    solve();
return 0;
}
