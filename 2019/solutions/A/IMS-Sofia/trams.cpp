#include<iostream>
#include<vector>
#include<stack>
using namespace std;

const int bla=50005;
vector<int> susedi[bla],put[bla];
int used[bla],maxx[bla];
stack<int> s;

void dfs(int vruh,int koi){
    used[vruh]++;
    put[koi].push_back(vruh);
    s.push(vruh);
    while(!s.empty()){
        vruh=s.top();
        s.pop();
        for(int i=0;i<susedi[vruh].size();i++){
            if(used[susedi[vruh][i]]<maxx[susedi[vruh][i]]){
                s.push(susedi[vruh][i]);
                used[susedi[vruh][i]]++;
                put[koi].push_back(vruh);
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        maxx[a]++;
        maxx[b]++;
        susedi[a].push_back(b);
        susedi[b].push_back(a);
    }
    int puti=0;
    for(int i=1;i<=n;i++){
        while(used[i]<maxx[i]){
            dfs(i,puti);
            puti++;
        }
    }
    cout<<puti<<"\n";
    for(int i=0;i<puti;i++){
        cout<<put[puti].size()<<" ";
        for(int j=0;j<put[puti].size();j++){
            cout<<put[puti][i]<<" ";
        }
        cout<<"\n";
    }
    return  0;
}
