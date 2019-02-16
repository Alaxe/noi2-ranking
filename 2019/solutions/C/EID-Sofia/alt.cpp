#include<bits/stdc++.h>
using namespace std;
int k, m, n;
long long sum=0, mem[51][51];
long long f(int ch, int i){
    if(i==(n-1) and ch<m and ch>0)return 1;
    if(i>n)return 0;
    if(ch>=m)return 0;
    if(ch<=0)return 0;
    if(mem[ch][i]==0){
        mem[ch][i]=f(ch+k, i+1)+f(ch-k, i+1);
    }
    return mem[ch][i];
}
int main() {
    cin>>k>>m>>n;
    for(int i=1; i<m; i++){
        sum=sum+f(i, 0);
    }
    cout<<sum<<endl;
    return 0;
}

