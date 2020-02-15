#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],bL[100001],bR[100001],br[100001];
int main(){
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
    br[a[i]]++;
}
cin>>m;
for(int i=0;i<m;i++){
    cin>>bL[i]>>bR[i];
    int sum=0;
    for(int i1=bL[i];i1<=bR[i];i1++){
        sum+=br[i1];
    }
    cout<<sum<<endl;
}
return 0;
}
