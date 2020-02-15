#include<bits/stdc++.h>
using namespace std;
long long mas[100001];
long long dp[100001];
long long dp2[100001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    cout.tie(NULL);
long long N;
cin>>N;
for(long long i=0;i<N;i++){
    cin>>mas[i];
}
sort(mas,mas+N);
dp[0]=0;
long long broi=0;
for(long long i=1;i<100001;i++){
    if(mas[broi]>=i){
        dp[i]=broi;
    }else{
        while(broi<N && i>mas[broi]){
            broi++;
        }
        if(broi!=N){
        dp[i]=broi;
        }else{
        dp[i]=-1;
        }
    }
}
for(long long i=0;i<mas[0];i++){
    dp2[i]=-1;
}
broi=0;
for(long long i=mas[0];i<100001;i++){
    while(broi<N-1 && i>=mas[broi+1]){
        broi++;
    }
    dp2[i]=broi;
}
long long M,a,b;
cin>>M;
for(long long i=0;i<M;i++){
    cin>>a>>b;
    if(dp[a]==-1|| dp2[b]==-1 ){
        cout<<0<<"\n";
    }else{
        cout<<dp2[b]-dp[a]+1<<"\n";
    }
}
return 0;
}
