#include<iostream>
#define endl '\n'
using namespace std;
const int MAXN=1e5+3;
int nums[MAXN],counter[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>nums[i];
        ++counter[nums[i]];
    }
    for(int i=1;i<MAXN;++i){
        counter[i]+=counter[i-1];
    }
    int m;
    cin>>m;
    for(int i=0;i<m;++i){
        int l,r;
        cin>>l>>r;
        cout<<counter[r]-counter[l-1]<<endl;
    }
return 0;
}
