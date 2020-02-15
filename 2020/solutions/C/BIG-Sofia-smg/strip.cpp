#include<bits/stdc++.h>
using namespace std;
int n,k,ans[1000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    if(k-1<n-k){
            ans[1]=n-(k-1);
        for(int i=k-2;i>0;i--){
            ans[k-i]=(ans[k-1-i]+1)*(ans[1]/2);
            if(ans[1]%2!=0){
                ans[k-i]+=(ans[k-1-i]+1)/2;
            }
            if(k-i>2){
                ans[k-i]-=(k-i+1)/2;
            }
        }
        if(ans[k-1]==0){
            ans[k-1]++;
        }
        cout<<ans[k-1]<<"\n";
    }else{
          ans[1]=n-(n-k);
        for(int i=k+2;i<=n;i++){
            ans[i-k]=(ans[i-1-k]+1)*(ans[1]/2);
            if(ans[1]%2!=0){
                ans[i-k]+=(ans[i-1-k]+1)/2;
            }
            if(i-k>2){
                ans[i-k]-=(i-k+1)/2;
            }
          //  cout<<ans[i-k]<<"\n";
        }
        if(ans[n-k]==0){
            ans[n-k]=1;
        }
        cout<<ans[n-k]<<"\n";
    }
    return 0;
}
