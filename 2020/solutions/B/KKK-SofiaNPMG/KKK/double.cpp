#include<iostream>
using namespace std;
int n=200,w1=200,w2=200;
int w[205];
int memo[205][205][205];
int calc(int cn,int cw1,int cw2){
    if(cn==n){
        return cw1+cw2;
    }
    if(memo[cn][cw1][cw2]!=-1)return memo[cn][cw1][cw2];
    int ans=calc(cn+1,cw1,cw2);
    if(cw1+w[cn]<=w1){
        ans=max(ans,calc(cn+1,cw1+w[cn],cw2));
    }
    if(cw2+w[cn]<=w2){
        ans=max(ans,calc(cn+1,cw1,cw2+w[cn]));
    }
    return memo[cn][cw1][cw2]=ans;
}
int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    for(int a=0;a<205;a++){
        for(int b=0;b<205;b++){
            for(int c=0;c<205;c++){
                memo[a][b][c]=-1;
            }
        }
    }
    cin>>n>>w1>>w2;
    for(int i=0;i<n;i++){
            //w[i]=i+1;
        cin>>w[i];
    }
    cout<<calc(0,0,0)<<endl;
    return 0;
}
