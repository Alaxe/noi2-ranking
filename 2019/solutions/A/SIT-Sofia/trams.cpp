#include<bits/stdc++.h>
using namespace std;
const long long maxN=50001;
vector<pair<long long,long long > >susedi[maxN];
long long pos[maxN];
long long brel[maxN];
queue<long long >otg[maxN];
stack<long long>obh;
int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(0);
long long n,m,a=0,b=0,nach=0,sum=0,br=0,c=0;
cin>>n>>m;
for(int i=0;i<m;i++){
    cin>>a>>b;
    susedi[a].push_back({b,false});
    susedi[b].push_back({a,false});
    pos[a]++;
    pos[b]++;

}
bool finds=false;
for(int i=1;i<=n;i++){
        sum+=pos[i];

    if(pos[i]>0 and pos[i]%2==1 and finds==false){
        nach=i;
            finds=true;
    }
}

if(nach==0){
nach=1;
}
obh.push(nach);

while(sum>0){
a=obh.top();
obh.pop();
brel[br]++;
otg[br].push(a);
 bool isok=false;
for(int i=0;i<susedi[a].size();i++){
    b=susedi[a][i].first;
    c=susedi[a][i].second;

    if(c==false){
            isok=true;
        obh.push(b);
        susedi[a][i].second=true;
        for(int j=0;j<susedi[b].size();j++){
            c=susedi[b][j].first;
            if(c==a){
                susedi[b][j].second=true;
                break;
            }
        }
        pos[a]--;
        pos[b]--;
        sum-=2;
        break;
    }
}
if(isok==false){
    br++;
    while(obh.empty()==false){
        obh.pop();
    }
   // cout<<sum<<"\n";
    //system("pause");
    bool isfirst=false;
    long long evfir=1;
    nach=0;
    for(int i=1;i<=n;i++){


    if(pos[i]>0 and pos[i]%2==1){
        nach=i;
      break;
    }else{
        if(pos[i]>0){
            if(pos[i]%2==0 and isfirst==false){
                isfirst=true;
                evfir=i;
            }
        }
    }
    }
    if(nach==0){
        nach=evfir;
    }
   // cout<<nach<<" "<<sum<<"\n";
    obh.push(nach);
}else{
if(sum==0){
    otg[br].push(obh.top());
    br++;
}
}

}
cout<<br<<"\n";
for(int i=0;i<br;i++){
        cout<<otg[i].size()<<" ";
    while(otg[i].empty()==false){
        a=otg[i].front();
        otg[i].pop();
        cout<<a<<" ";
    }
    cout<<"\n";
}
return 0;
}
/*
8 12
2 3
3 4
5 4
2 6
4 8
6 8
8 7
5 7
6 7
1 2
1 5
1 3
*/
