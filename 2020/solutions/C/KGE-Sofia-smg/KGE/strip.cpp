#include<bits/stdc++.h>
using namespace std;
long long N,K;
long long mas[51][51][51][51];
long long f(long long a,long long b,long long ka,long long kb){
    if(ka==0 || kb==0 || ka==N-1 || kb==N-1){
        return 1;
    }
    if(mas[a][b][ka][kb]){
        return mas[a][b][ka][kb];
    }
    if(a>b){
            mas[a][b][ka][kb]=f(a+1,b,ka-1,kb)+f(a,a+1,ka,kb+1);
    }else{
        mas[a][b][ka][kb]=f(b+1,b,ka-1,kb)+f(a,b+1,ka,kb+1);
    }
}
long long dp[51][51];
int main(){

    cin>>N>>K;
    if(K!=1 && K!=N){
    cout<<f(1,2,K-1,K)+f(2,1,K-2,K-1)<<"\n";
    }else{
        cout<<1<<"\n";
    }
return 0;
}
