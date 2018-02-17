#include<bits/stdc++.h>
using namespace std;
long long tek,z,s,t,dp[64][64][2][2];
long long rec(long long tekbit,long long cnt,bool is,bool ls)
{
    if(tekbit==-1)return (cnt==z);
    if(dp[tekbit][cnt][is][ls]!=-1)return dp[tekbit][cnt][is][ls];
    //cout<<tekbit<<" "<<cnt<<" "<<hb<<" "<<ls<<endl;
    //if(hb==1)Sleep(500);
    //cout<<tekbit<<endl;
    long long x=1;
    for(int i=1;i<=tekbit;i++)
    x*=2;
    if(is==1)
    {
        if((x&tek)!=0)
        {
            return dp[tekbit][cnt][is][ls]=rec(tekbit-1,cnt+1,is,1)+rec(tekbit-1,cnt,is,ls);
        }
        else if(ls)
        {
            return dp[tekbit][cnt][is][ls]=rec(tekbit-1,cnt+1,is,1)+rec(tekbit-1,cnt,is,ls);
        }
        else
        {
            return dp[tekbit][cnt][is][ls]=rec(tekbit-1,cnt+1,is,ls);
        }
    }
    else
    {
        return dp[tekbit][cnt][is][ls]=rec(tekbit-1,cnt+1,is,ls)+rec(tekbit-1,cnt,is,ls);
    }
    //cout<<x<<endl;
    /*if(x-tek<=0)hb=1;
    if(hb==0)return rec(tekbit-1,cnt,hb,ls);
    if(ls==0)
    return rec(tekbit-1,cnt+1,hb,0)+rec(tekbit-1,cnt,hb,0)+rec(tekbit-1,0,0,0);
    else
    return rec(tekbit-1,cnt+1,hb,0)+rec(tekbit-1,cnt,hb,1)+rec(tekbit-1,0,0,0);
    */
}
long long sol(long long x)
{
    if(x==0)
        return 0;
    if(x==1)
        return (z==0);
    tek=x;
    long long bigbit=0,num=1;
    for(;;)
    {
        num*=2;
        bigbit++;
        if(num>x)
        {
            bigbit--;
            break;
        }
    }
    long long sum = 0;
    memset(dp,-1,sizeof(dp));
    sum += rec(bigbit-1,0,1,0);
    for(int i=bigbit-1;i>=1;i--)
    {
        memset(dp,-1,sizeof(dp));
        sum += rec(i-1,0,0,0);
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s>>t>>z;
    //cout<<sol(t)<<" "<<sol(s-1)<<endl;
    cout<<sol(t)-sol(s-1)<<endl;
    return 0;
}
