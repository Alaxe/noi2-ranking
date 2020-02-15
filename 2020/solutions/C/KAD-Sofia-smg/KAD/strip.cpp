#include<iostream>
#include<cstring>
#define endl '\n'
using namespace std;
const int MAXN=53;
long long dp[MAXN][MAXN];
long long sol(int l, int r, int n){
    if(l==0 and r==n+1){
        return 1;
    }
    long long& ans=dp[l][r];
    if(ans!=-1){
        return ans;
    }
    ans=0;
    if(r<=n){
        ans+=sol(l,r+1,n);
    }
    if(l>0){
        ans+=sol(l-1,r,n);
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    cout<<sol(k-1,k+1,n)<<endl;
return 0;
}
