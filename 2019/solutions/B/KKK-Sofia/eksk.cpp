#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<long long>susedi[200002];
long long n;
long long a,b;
long long from[200002];
queue<long long>curr;
vector<long long>path;
long long optA[200002];
long long optB[200002];
long long calcPath(long long v,long long p){
    long long len=1;
    for(long long i=0;i<susedi[v].size();i++){
        if(susedi[v][i]==p)continue;
        len=max(len,calcPath(susedi[v][i],v)+1);
    }
    return len;
}
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin>>n;
    for(long long i=0;i<n-1;i++){
        cin>>a>>b;
        susedi[a].push_back(b);
        susedi[b].push_back(a);
    }
    cin>>a>>b;
    from[a]=-1;
    curr.push(a);
    while(!curr.empty()){
        long long c=curr.front();
        curr.pop();
        for(long long i=0;i<susedi[c].size();i++){
            if(from[susedi[c][i]]==0){
                from[susedi[c][i]]=c;
                curr.push(susedi[c][i]);
            }
        }
    }
    long long c=b;
    while(c!=-1){
        path.push_back(c);
        c=from[c];
    }
    long long prevopt=0;
    n=path.size();
    for(long long i=0;i<path.size();i++){
        long long opt=0;
        for(long long j=0;j<susedi[path[i]].size();j++){
            if((i>0 && susedi[path[i]][j]==path[i-1]) || (i<n-1 && susedi[path[i]][j]==path[i+1]))continue;
                //cout<<"sused : "<<i<<" "<<susedi[i][j]<<endl;
                opt=max(opt,calcPath(susedi[path[i]][j],path[i]));
        }
        //cout<<i<<" "<<opt<<endl;
        prevopt=max(i+opt+1,prevopt);
        optA[i]=prevopt;
    }
    prevopt=0;
    for(long long i=path.size()-1;i>=0;i--){
        long long opt=0;
        for(long long j=0;j<susedi[path[i]].size();j++){
            if((i>0 && susedi[path[i]][j]==path[i-1]) || (i<n-1 && susedi[path[i]][j]==path[i+1]))continue;
                //cout<<"sused : "<<i<<" "<<susedi[i][j]<<endl;
                opt=max(opt,calcPath(susedi[path[i]][j],path[i]));
        }
        //cout<<i<<" "<<opt<<endl;
        prevopt=max((n-i-1)+opt+1,prevopt);
        optB[i]=prevopt;
    }
    long long ans=0;
    for(long long i=0;i<path.size()-1;i++){
        //cout<<optA[i]<<" "<<optB[i+1]<<endl;
        ans=max(ans,min(optA[i],optB[i+1]));
    }
    cout<<ans<<endl;
    return 0;
}
