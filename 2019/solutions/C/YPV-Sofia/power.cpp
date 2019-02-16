#include<iostream>
using namespace std;
int arr[10001];
int brNeed[44];
int brNow[44];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int del;
    for(int i=0;i<n;i++){
        del=2;
        while(arr[i]>1){
            if(arr[i]%del==0){
                brNow[del]++;
                arr[i]=arr[i]/del;
            }else{
                brNeed[del]=max(brNeed[del],brNow[del]);
                del++;
                brNow[del]=0;
            }
        }
        brNeed[del]=max(brNeed[del],brNow[del]);
        brNow[del]=0;
    }
    long long ans=1;
    int powtorenie=0;
    for(int i=0;i<=43;i++){
        if(brNeed[i]>0){
            if(brNeed[i]%k==0) powtorenie=brNeed[i]/k;
            else powtorenie=brNeed[i]/k+1;
            for(int j=1;j<=powtorenie;j++) ans*=i;
        }
    }
    cout<<ans<<endl;
return 0;
}

