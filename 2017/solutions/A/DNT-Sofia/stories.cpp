#include<iostream>
using namespace std;
long long stories[10000000];
int n,k;
long long findStory(int d){
    long long m=0;
    for(int i=d-k;i<d;i++){
        if(stories[i]>m){
            m=stories[i];
        }
    }
    return m;
}
int main(){
    long long mul,add,mod;
    cin>>n>>k;
    cin>>stories[0];
    cin>>mul>>add>>mod;
    for(int i=1;i<n;i++){
        stories[i]=(stories[i-1]*mul+add)%mod;
    }
    long long res=0;
    for(int i=0;i<=n;i++){
        res=res+findStory(i);
    }
    cout<<res<<endl;
    return 0;
}
