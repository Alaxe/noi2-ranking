#include<iostream>

using namespace std;

long long mod;
long long n,m,p,q;
long long dp[20001][2];
bool b[20001][2];

long long solve(long long currWeight,bool state)
{
    if(currWeight>=n)return 1;
    if(b[currWeight][state])return dp[currWeight][state];
    
    long long& res=dp[currWeight][state];
    
    b[currWeight][state]=1;
    
    if(state)
    {
        res+=solve(currWeight-q,0);
        res+=solve(currWeight,0);
    }
    else
    {
        res+=solve(currWeight+p,1);
    }
    
    while(res>=mod)res-=mod;
    
    
    return res;
}

int main ()
{
    mod=(long long)1<<30;
    
    ios::sync_with_stdio(false);
    
    cin>>m>>n>>p>>q;
    
    cout<<(long long)solve(m,0)<<endl;
    
    return 0;
}