#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, u;
    cin>>n>>u;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=0;i<n;++i){
        cout<<u/3+a[i]/2<<' ';
    }
    cout<<'\n';
    return 0;
}

