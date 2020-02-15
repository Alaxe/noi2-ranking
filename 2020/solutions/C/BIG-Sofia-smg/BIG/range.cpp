#include<bits/stdc++.h>
using namespace std;
int n,a[100001],m,z1,z2,br[100001],ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        br[a[i]]++;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>z1>>z2;
        for(int i1=z1;i1<=z2;i1++){
            ans+=br[i1];
        }
        cout<<ans<<"\n";
        ans=0;
    }
    return 0;
}

