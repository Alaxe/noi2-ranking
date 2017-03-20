#include<iostream>
#include<algorithm>
using namespace std;
int n, dp[10001], a[10001], sum;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=i;j>=0;j--){
            if(a[i]>a[j])dp[i]+=dp[j]+1;
        }
        sum += dp[i];
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    cout<<sum<<endl;
}
