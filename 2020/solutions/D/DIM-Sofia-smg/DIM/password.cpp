#include<bits/stdc++.h>
using namespace std;
pair<int,char> pr[5003];
pair<int,char> suf[5003];
string a;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(i==0 || a[i]!=pr[i-1].second){
            pr[i].first=1;
            pr[i].second=a[i];
        }else{
            pr[i].first=pr[i-1].first+1;
            pr[i].second=pr[i-1].second;
        }
        //cout<<pr[i].first<<" "<<pr[i].second<<endl;
    }
    //cout<<endl;
    for(int i=a.size()-1;i>=0;i--){
        if(i==a.size()-1 || a[i]!=suf[i+1].second){
            suf[i].first=1;
            suf[i].second=a[i];
        }else{
            suf[i].first=suf[i+1].first+1;
            suf[i].second=suf[i+1].second;
        }
    }
    for(int i=0;i<a.size();i++){
        if(pr[i].first%3==0){
            for(char j='a';j<='z';j++){
                if(j==a[i])continue;
                if(suf[i+1].second==j && suf[i+1].first>=2)continue;
                a[i]=j;
                break;
            }
        }
    }
    cout<<a;
    cout<<"\n";
return 0;
}
