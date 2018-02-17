#include<iostream>
using namespace std;
long long n,m,memo[271][271];
long long dinami4no(long long b,long long k){
if(k==0){
    return 1;
}
if(memo[b][k]!=0){
        return memo[b][k];
}
for(long long i=1;i<=b and i<=k;i++){
    memo[b][k]+=dinami4no(i,(k-i));
}
return memo[b][k];
}
int main(){
cin>>n>>m;
cout<<dinami4no(m,n)<<"\n";
return 0;
}
