#include<bits/stdc++.h>
using namespace std;
int k,m,n;
unsigned long long dp[105][105];
unsigned long long sol(int number,int length){
    if(number<1 or number>=m) return 0;
    if(length>n) return 0;
    if(dp[number][length]!=0) return dp[number][length];
    if(length==n) return 1;
    dp[number][length]=sol(number-k,length+1)+sol(number+k,length+1);
    if(length==1) dp[number][length]+=sol(number-1,length);
    return dp[number][length];
}
int main(){
    cin>>k>>m>>n;
    cout<<sol(m-1,1)<<endl;
return 0;
}
