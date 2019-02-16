#include<bits/stdc++.h>
using namespace std;

unsigned long long dp[55][55];
int jump, bound, len;

unsigned long long getDP(int it, int pos){
    if(it>=0&&it<len&&pos>0&&pos<bound){
        return dp[it][pos];
    }
    return 0;
}

int main(){
    cin>>jump>>bound>>len;
    for(int i=1;i<bound;i++){
        dp[0][i]=1;
    }
    for(int i=1;i<len;i++){
        for(int j=1;j<bound;j++){
            dp[i][j]=getDP(i-1, j-jump)+getDP(i-1, j+jump);
        }
    }
    unsigned long long out=0;
    for(int i=1;i<bound;i++){
        out+=dp[len-1][i];
    }
    cout<<out<<endl;
    return 0;
}
