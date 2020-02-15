#include<bits/stdc++.h>
using namespace std;
long long dp[51][51], N, k;
long long f(int left, int right){
    if(left==0 or right==0)return 1;
    if(dp[left][right]!=0)return dp[left][right];
    dp[left][right]=f(left-1, right)+f(left, right-1);
    dp[right][left]=dp[left][right];
    return dp[left][right];
}
int main() {
    cin>>N>>k;
    cout<<f(k-1, N-k)<<endl;
    return 0;
}
