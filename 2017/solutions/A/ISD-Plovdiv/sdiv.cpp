#include<bits/stdc++.h>
using namespace std;
int main()
{
    #define int long long
    string s;
    int n,m;
    cin>>s>>n>>m;
    int dp[1024];
    int crr[1024];
    for(int i=0;i<=n;i++)crr[i]=0,dp[i]=0;
    for(int i=0;i<s.size();i++)
    {
        int crc=(int)(s[i]-'0');
        for(int j=0;j<n;j++)
        {
            int mx=(10*n+crc-j)/n;
            for(int o=0;o<mx;o++)
            {
                if((o*n+j-crc)%10==0)
                    crr[j]=(crr[j]+dp[(o*n+j-crc)/10])%m;
            }
        }
        crr[crc%n]=(crr[crc%n]+1)%m;
        for(int j=0;j<n;j++)dp[j]=crr[j];
    }
    cout<<dp[0]<<endl;
    return 0;
}


