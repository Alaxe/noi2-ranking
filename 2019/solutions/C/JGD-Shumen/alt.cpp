#include<iostream>
using namespace std;
const int maxn = 51;
int k,m,n;
int br;
int dp[maxn];
int main()
{

    cin>>k>>m>>n;
    for(int i=1;i<m;i++)
        for(int j=1;j<=n;j++)
    {
        dp[1]=i;
        br++;
        if(dp[j]+k<m)
        {
            dp[j]+=k;
            br++;
        }
        else if(dp[j]-k>0)
        {
            dp[j]=dp[j]-k;
            br++;
        }
    }
    cout<<br/4<<endl;
    return 0;
}
