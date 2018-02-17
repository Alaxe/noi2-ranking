#include<iostream>
using namespace std;
long long dp[1024][1024];
const long long mod=123456789012345;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,i,j,d,a[1024];
    long long otg=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            d=a[j]-a[i];
            if(d>0){
                dp[d][j]+=dp[d][i]+1;
                dp[d][j]%=mod;
            }
        }
    }
    for(d=1;d<1001;d++){
        for(i=0;i<n;i++){
            otg+=dp[d][i];
            otg%=mod;
        }
    }
    cout<<otg<<"\n";
    return 0;
}
