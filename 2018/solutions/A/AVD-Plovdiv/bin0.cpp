#include<bits/stdc++.h>
using namespace std;
long long l,r,z,tekhigh,pow2[62];
long long dp[64][64][2][2];
long long f(int tek,int br,bool ishighest,bool smaller)
{
    //if(ishighest)cout<<tek<<" "<<br<<" "<<ishighest<<" "<<smaller<<endl;
    if(tek==-1)
        return (br==z);
    if(dp[tek][br][ishighest][smaller]!=-1)
        return dp[tek][br][ishighest][smaller];
    if(ishighest)
    {
        long long tekbit=pow2[tek];
        if((tekhigh&tekbit)!=0)
        {
            dp[tek][br][ishighest][smaller]=f(tek-1,br+1,ishighest,1)+f(tek-1,br,ishighest,smaller);
        }
        else if(smaller)
        {
            dp[tek][br][ishighest][smaller]=f(tek-1,br+1,ishighest,1)+f(tek-1,br,ishighest,smaller);
        }
        else
            dp[tek][br][ishighest][smaller]=f(tek-1,br+1,ishighest,smaller);
    }
    else
    {
        dp[tek][br][ishighest][smaller]=f(tek-1,br+1,ishighest,smaller)+f(tek-1,br,ishighest,smaller);
    }
    return dp[tek][br][ishighest][smaller];
}
 long long ans(long long now)
{
    long long sum = 0;
    if(now==0)
    {
        return 0;
    }
    if(now==1)
    {
        return (z==0);
    }
    int biggestbit=0;
    for(int i=1;;i++)
        if(now<pow2[i])
        {
            biggestbit=i-1;
            break;
        }
    memset(dp,-1,sizeof(dp));
    tekhigh=now;
    sum += f(biggestbit-1,0,1,0);
    for(int i=biggestbit-1;i>=1;i--)
    {
        memset(dp,-1,sizeof(dp));
        sum += f(i-1,0,0,0);
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>l>>r>>z;
    pow2[0]=1;
    for(int i=1;i<=61;i++)
        pow2[i]=pow2[i-1]*2;
    cout<<ans(r)-ans(l-1)<<endl;
    return 0;
}
