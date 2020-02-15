#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAXN=1e5+5;
bool used[MAXN];

vector<pair<int,bool> > susedi[MAXN];
queue<int> q;
int fs[2*MAXN],ind[2*MAXN];
bool art[2*MAXN];
bool imaLiGo[MAXN];

int index(int vruh,int target){
    for(int i=0;i<susedi[vruh].size();i++){
        if(susedi[vruh][i].first == target){
            return i;
        }
    }
}

int br=0;
void dfs(int vruh,int curr){
    //cout<<vruh<<" ";
    used[vruh]=true;
    fs[curr]=vruh;
    imaLiGo[vruh]=true;
    art[curr]=true;
    for(int i=0;i<susedi[vruh].size();i++){
        if(!used[susedi[vruh][i].first]){
            ind[curr+1]=i;
            dfs(susedi[vruh][i].first,curr+1);
        }else if(curr>0 and fs[curr-1]!=susedi[vruh][i].first and imaLiGo[susedi[vruh][i].first]){
            //cout<<"@@@"<<curr<<" "<<susedi[vruh][i].first<<"\n";
            for(int j=curr;j>=0;j--){
                if(fs[j]==susedi[vruh][i].first){
                    break;
                }
                art[j]=false;
            }
        }
    }
    if(curr>0 and art[curr]){
        //cout<<"\n#"<<fs[curr]<<" "<<(curr>0?fs[curr-1]:-1)<<"#\n";
        susedi[fs[curr]][index(fs[curr],fs[curr-1])].second=true;
        susedi[fs[curr-1]][ind[curr]].second=true;///erase
        br++;
        ///mahni go
    }
    imaLiGo[vruh]=false;
}

long long comp(int vruh){
    long long br=0;
    used[vruh]=true;
    q.push(vruh);
    while(!q.empty()){
        vruh=q.front();
        br++;
        q.pop();
        for(int i=0;i<susedi[vruh].size();i++){
            if(!used[susedi[vruh][i].first] and !susedi[vruh][i].second){
                q.push(susedi[vruh][i].first);
                used[susedi[vruh][i].first]=true;
            }
        }
    }
    return br;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int vurhove,rebra;
    cin>>vurhove>>rebra;
    for(int i=0;i<rebra;i++){
        int a,b;
        cin>>a>>b;
        susedi[a].push_back({b,false});
        susedi[b].push_back({a,false});
    }
    dfs(1,0);
    //cout<<"\n"<<br<<"\n";
    long long otg=0;
    for(int i=1;i<=vurhove;i++){
        used[i]=false;
    }
    for(int i=1;i<=vurhove;i++){
        if(!used[i]){
            long long curr=comp(i);
            otg=otg+curr*(curr-1)/2;
        }
    }
    cout<<otg<<"\n";
    return 0;
}
