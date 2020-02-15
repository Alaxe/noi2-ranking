#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll maxN=100001;
vector<pair<ll,ll> > adj[maxN];
ll discoveryTime[maxN],lowestTime[maxN];
queue<pair<ll,ll> > toMakeUnusable;
bool visited[maxN];
ll countV=0;

void markAsUnusable(ll a,ll b){
    bool fin1=false,fin2=false;
   for(int i=0;i<max(adj[a].size(),adj[b].size());i++){
       if(i<adj[a].size()){
          if(adj[a][i].first==b){
            adj[a][i].second=0;
            fin1=true;
          }
       }
       if(i<adj[b].size()){
          if(adj[b][i].first==a){
            adj[b][i].second=0;
            fin2=true;
          }
       }
       if(fin1==true and fin2==true){
        return;
       }
   }
}

void DFS_Articulation(ll currV,ll currTime){
   discoveryTime[currV]=currTime;
   lowestTime[currV]=currTime;
  for(int i=0;i<adj[currV].size();i++){
        ll nextV=adj[currV][i].first;
    if(discoveryTime[nextV]==0){
        DFS_Articulation(nextV,currTime+1);
        if(lowestTime[nextV]==discoveryTime[nextV]){
            toMakeUnusable.push({currV,nextV});
        }else{
            lowestTime[currV]=min(lowestTime[currV],lowestTime[nextV]);
        }
    }else{
      if(discoveryTime[nextV]!=currTime-1){
        lowestTime[currV]=min(lowestTime[nextV],lowestTime[currV]);
      }
    }
  }

}

void DFS(ll currV){
     countV++;
     visited[currV]=true;
    for(int i=0;i<adj[currV].size();i++){
        ll nextV=adj[currV][i].first,usable=adj[currV][i].second;
        if(usable==1){
            if(visited[nextV]==false){
                DFS(nextV);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

ll n,m,a,b,ans=0;
cin>>n>>m;
for(int i=0;i<m;i++){
    cin>>a>>b;

    adj[a].push_back({b,1});
    adj[b].push_back({a,1});
}
DFS_Articulation(1,1);
while(toMakeUnusable.empty()==false){
   a=toMakeUnusable.front().first;
   b=toMakeUnusable.front().second;
   //cout<<a<<" "<<b<<"\n";
   markAsUnusable(a,b);
   toMakeUnusable.pop();
}
for(int i=1;i<=n;i++){
        countV=0;
    if(visited[i]==false){
        DFS(i);
        ans+=(countV*(countV-1))/2;
    }
}
cout<<ans<<"\n";
return 0;
}
/*
5 5
1 2
2 3
3 1
2 4
2 5

5 5
1 2
2 3
3 4
4 5
5 1

8 9
1 2
1 3
2 4
3 4
4 5
5 6
5 7
6 8
7 8

6 6
1 2
2 3
2 4
3 5
4 6
5 6

7 8
1 2
2 3
1 4
4 5
1 5
5 6
6 7
5 7

8 9
1 2
2 3
1 4
1 5
4 5
5 6
6 7
6 8
7 8
*/
