#include<bits/stdc++.h>
using namespace std;
int dp[55][55];
bool bo[55][55];
int f(int a,int b){
    if(a==0 || b==0) return 1;
    if(bo[a][b])return dp[a][b];
    bo[a][b]=true;
    return dp[a][b]=f(a-1,b)+f(a,b-1);
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<f(b-1,a-b)<<endl;
    return 0;
}
