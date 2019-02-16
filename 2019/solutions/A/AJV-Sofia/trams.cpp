#include<iostream>
#include<map>
#include<vector>
#include<stack>
using namespace std;
long long n,m,f=0,a,b;
bool u[100001];
vector<long long>sys[100001];
map<pair<long long,long long>,long long>number;
vector<long long>NaTovaRebro[100001];
vector<long long>fR;
map<pair<long long,long long>,bool>used;
stack<long long>pyt[100001];
vector<long long>fPr[100001];
bool check[100001];
bool dfs(long long from){
    for(long long i=0;i<sys[from].size();i++){
        if(used[make_pair(from,sys[from][i])]==0 and used[make_pair(sys[from][i],from)]==0){
            used[make_pair(from,sys[from][i])]=1;
            pyt[f].push(sys[from][i]);
            dfs(sys[from][i]);
            return 0;
        }
    }
    return 0;
}
int main(){
cin>>n>>m;
for(long long i=0;i<m;i++){
    cin>>a>>b;
    sys[a].push_back(b);
    sys[b].push_back(a);
}
for(long long i=1;i<=n;i++){
    if(sys[i].size()%2==1){
        pyt[f].push(i);
        dfs(i);
        f++;
    }
}
for(long long i=1;i<=n;i++){
    if(sys[i].size()%2==0){
        pyt[f].push(i);
        dfs(i);
        f++;
    }
}
cout<<f<<"\n";
for(long long i=0;i<f;i++){
    cout<<pyt[i].size()<<" ";
    while(pyt[i].empty()==0){
        cout<<pyt[i].top()<<" ";
        pyt[i].pop();
    }
    cout<<"\n";
}
/*bool dali
for(long long i=1;i<=n;i++){
    if(sys[i].size()%2==1){
        connectIt(i);
    }
}*/
return 0;
}
