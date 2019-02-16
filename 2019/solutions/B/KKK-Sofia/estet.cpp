#include<iostream>
#include<set>
#include<ctime>
using namespace std;
int trees[100002];
int lis[100002];
int lds[100002];
int length[100002];
int length2[100002];
set<int>red;
int main(){
    int n=100000;
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>trees[i];
        //trees[i]=i+1;
    }
    red.insert(0);
    for(int i=0;i<n;i++){
        auto a=red.upper_bound(-trees[i]);
        red.insert(-trees[i]);
        int prev=-(*a);
        lis[i]=length[prev]+1;
        length[trees[i]]=length[prev]+1;
    }
    red.clear();
    red.insert(0);
    for(int i=n-1;i>=0;i--){
        auto a=red.upper_bound(-trees[i]);
        red.insert(-trees[i]);
        int prev=-(*a);
        lds[i]=length2[prev]+1;
        length2[trees[i]]=length2[prev]+1;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        //cout<<lis[i]<<" "<<lds[i]<<endl;
        ans=max(ans,lis[i]+lds[i]-1);
    }
    cout<<ans<<endl;
    return 0;
}
