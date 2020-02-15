#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll maxN=100001,bigMod=1000000001;
ll row[2][maxN];
bool possiblePositions[2][maxN];
vector<ll> equalByOne[2];
queue<pair<ll,ll> > equalElements[2];

void findPossiblePositions(ll rowId,ll rowLen,ll k,ll w){
    ll beginPosition=0,currK=1;
    if(w==1){
        for(int i=1;i<rowLen;i++){
          if(row[rowId][i]>row[rowId][i-1]){
            currK++;
            if(currK==k){
                possiblePositions[rowId][beginPosition]=true;
                beginPosition++;
                currK--;
            }
          }else{
            currK=1;
            beginPosition=i;
          }
        }
    }else{
         for(int i=1;i<rowLen;i++){
          if(row[rowId][i]==row[rowId][i-1]){
            currK++;
            if(currK==k){
                equalByOne[rowId].push_back(row[rowId][i]);
                possiblePositions[rowId][beginPosition]=true;
                beginPosition++;
                currK--;
            }
          }else{
            currK=1;
            beginPosition=i;
          }
        }
    }
}

ll createAnswerW2(ll n,ll m){
    ll fin=0;

if(equalByOne[0].empty()==true or equalByOne[1].empty()==true){
    return fin;
}
  ll beg=equalByOne[0][0],eCount=1;
    for(int i=1;i<equalByOne[0].size();i++){
            ll curr=equalByOne[0][i];
        if(curr==beg){
            eCount++;
        }else{
            equalElements[0].push({beg,eCount});
            //cout<<beg<<" "<<eCount<<"\n";
            eCount=1;
            beg=curr;
        }
    }
    equalElements[0].push({beg,eCount});

    beg=equalByOne[1][0];
    eCount=1;
      for(int i=1;i<equalByOne[1].size();i++){
            ll curr=equalByOne[1][i];
        if(curr==beg){
            eCount++;
        }else{
            equalElements[1].push({beg,eCount});
            eCount=1;
            beg=curr;
        }
    }
     equalElements[1].push({beg,eCount});

     while(equalElements[0].empty()==false and equalElements[1].empty()==false){
         ll el1=equalElements[0].front().first,el2=equalElements[1].front().first;
         ll oc1=equalElements[0].front().second,oc2=equalElements[1].front().second;
         if(el1!=el2){
            if(el1<el2){
                equalElements[0].pop();
            }else{
                equalElements[1].pop();
            }
         }else{
            // cout<<el1<<" "<<oc1<<" "<<oc2<<"\n";
            fin+=oc1*oc2;
             equalElements[0].pop();
             equalElements[1].pop();
         }
     }
     return fin;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
ll w,k,n,m,ans=0;
cin>>w>>k;
cin>>n;
for(int i=0;i<n;i++){
 cin>>row[0][i];
}
cin>>m;
for(int i=0;i<m;i++){
 cin>>row[1][i];
}
findPossiblePositions(0,n,k,w);
findPossiblePositions(1,m,k,w);
if(w==2){
    sort(equalByOne[0].begin(),equalByOne[0].end());
    sort(equalByOne[1].begin(),equalByOne[1].end());
    ans=createAnswerW2(n,m);
}else{
    for(int i=0;i<n;i++){
        if(possiblePositions[0][i]==true){
                ll myHash=1;
            for(int j=0;j<k;j++){
                myHash*=(7*row[0][i+j]+11);
                myHash%=bigMod;

            }
            equalByOne[0].push_back(myHash);
             //cout<<myHash<<" "<<i<<"\n";
        }
    }
    //cout<<"\n";
     for(int i=0;i<m;i++){
        if(possiblePositions[1][i]==true){
                ll myHash=1;
            for(int j=0;j<k;j++){
                myHash*=(7*row[1][i+j]+11);
                myHash%=bigMod;

            }
            equalByOne[1].push_back(myHash);
           // cout<<myHash<<" "<<i<<"\n";
        }
    }
    sort(equalByOne[0].begin(),equalByOne[0].end());
    sort(equalByOne[1].begin(),equalByOne[1].end());
    ans=createAnswerW2(n,m);
}
cout<<ans<<"\n";
return 0;
}
/*
2 3
11
3 4 4 4 4 5 6 6 6 6 7
16
3 6 6 6 4 4 4 5 6 6 6 7 7 6 6 6

1 2
6
2 1 3 4 3 6
6
3 6 1 3 6 7
*/
