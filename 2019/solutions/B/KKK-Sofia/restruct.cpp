#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<long long>susedi[5005];
long long len[5005];
long long n,k;
long long bfs(long long v){
    for(long long i=0;i<n;i++){
        len[i]=0;
    }
    len[v]=1;
    queue<long long>curr;
    curr.push(v);
    while(!curr.empty()){
        long long c=curr.front();
        curr.pop();
        for(long long i=0;i<susedi[c].size();i++){
            if(len[susedi[c][i]]==0){
                curr.push(susedi[c][i]);
                len[susedi[c][i]]=len[c]+1;
            }
        }
    }
    long long ans=0;
    for(long long i=0;i<n;i++){
        if(len[i]<0){
            return -1;
        }else{
            ans+=len[i];
        }
    }
    return ans;
}
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(long long i=0;i<n;i++){
        long long a;
        cin>>a;
        for(long long j=0;j<a;j++){
            long long b;
            cin>>b;
            susedi[b-1].push_back(i);
        }
    }
    long long opt=100000000000000;
    for(long long i=0;i<n;i++){
        long long curr=bfs(i);
        if(curr!=-1){
            opt=min(opt,curr);
        }
    }
    cout<<opt*k<<endl;
    return 0;
}
