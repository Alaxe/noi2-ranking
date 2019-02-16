#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;

const int bla=1e5+5;

struct dus{
    int x,y,num;
    bool isBall;
    const bool operator< (const dus & a) const{
        return a.y<y;
    }
};

struct dusk{
    int x,y,d;
}duski[bla];

set<dus> buk;
vector<dus> sortx;
vector<int> susedi[bla];

bool cmp1(dus a, dus b){
    if(a.x==b.x){
        return a.y>b.y;
    }
    return a.x<b.x;
}

bool cmp2(dus a, dus b){
    if(a.x==b.x){
        return a.y>b.y;
    }
    return a.x>b.x;
}

bool y[bla];
int topki[bla],otg[bla];

int used[bla];
queue<int> q;
void bfs(int vruh){
    used[vruh]=1;
    q.push(vruh);
    while(!q.empty()){
        vruh=q.front();
        q.pop();
        for(int i=0;i<susedi[vruh].size();i++){
            if(!used[susedi[vruh][i]]){
                used[susedi[vruh][i]]=used[vruh]+1;
                q.push(susedi[vruh][i]);
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int brduski,maxx=-1,maxy=-1;
    cin>>brduski;
    for(int i=1;i<=brduski;i++){
        cin>>duski[i].x>>duski[i].y>>duski[i].d;
        sortx.push_back({duski[i].x,duski[i].y,i,0});
        sortx.push_back({duski[i].x+duski[i].d,duski[i].y,i,0});
        maxx=max(maxx,duski[i].x);
        maxy=max(maxy,duski[i].y);
    }
    maxy+=2;
    int brtopki;
    cin>>brtopki;
    for(int i=0;i<brtopki;i++){
        cin>>topki[i];
        sortx.push_back({topki[i],maxy,i,1});
        maxx=max(maxx,topki[i]);
    }
    maxx+=2;
    ///##########################################
    sort(sortx.begin(),sortx.end(),cmp1);
    buk.insert({0,0,0,0});
    for(int i=0;i<sortx.size();i++){
        if(!sortx[i].isBall){
            if(!y[sortx[i].y]){
                auto it=buk.insert(sortx[i]).first;
                it++;
                susedi[it->num].push_back(sortx[i].num);
                y[sortx[i].y]=true;
            }else{
                int ind=sortx[i].num;
                buk.erase({duski[ind].x,duski[ind].y,ind,0});
                y[sortx[i].y]=false;
            }
        }else{
            auto it=buk.insert(sortx[i]).first;
            auto cp=it;
            it++;
            otg[sortx[i].num]=it->num;
            buk.erase(cp);

        }
    }
    buk.erase({0,0,0,0});
    ///##########################################
    sort(sortx.begin(),sortx.end(),cmp2);
    buk.insert({maxx,0,0,0});
    for(int i=0;i<sortx.size();i++){
        if(!sortx[i].isBall){
            if(!y[sortx[i].y]){
                auto it=buk.insert(sortx[i]).first;
                it++;
                susedi[it->num].push_back(sortx[i].num);
                y[sortx[i].y]=true;
            }else{
                int ind=sortx[i].num;
                buk.erase({duski[ind].x,duski[ind].y,ind,0});
                y[sortx[i].y]=false;
            }
        }else{
            auto it=buk.insert(sortx[i]).first;
            auto cp=it;
            it++;
            otg[sortx[i].num]=it->num;
            buk.erase(cp);
        }
    }
    ///##########################################
    bfs(0);
    for(int i=0;i<brtopki;i++){
        cout<<used[otg[i]]-1<<" ";
    }cout<<endl;
    return 0;
}
