#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,ans;
int a[100005],br[100005],pr[100005];
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
    br[a[i]]++;
}
for(int i=0;i<=100000;i++){
    pr[i+1]+=br[i];
    pr[i+1]+=pr[i];
}
cin>>m;
for(int i=0;i<m;i++){
    cin>>x>>y;
    cout<<pr[y+1]-pr[x]<<"\n";
}
return 0;
}
