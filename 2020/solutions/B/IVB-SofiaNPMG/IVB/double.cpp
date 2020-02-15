///#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
int a[200], glo;
int d[200][200];
int n, w1, w2;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>w1>>w2;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    cout<<w1+w2-2<<'\n';
    return 0;
}
