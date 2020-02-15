#include<bits/stdc++.h>
using namespace std;
int br[100005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a,m,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        br[a]++;
    }
    for(int i=1;i<=100000;i++){
        br[i]+=br[i-1];
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        cout<<br[b]-br[a-1]<<"\n";
    }
    return 0;
}
/*
6
9 1 3 10 3 4
3
1 4
9 12
15 20
*/
