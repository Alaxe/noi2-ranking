#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,k;
    cin>>n>>k;
    //n=1000000;k=1000000;
    long long ans=n*n-n;
    long long more=k-1;
    if(more!=0){
        ans+=(more/2+more%2)*((2*n-2)+1);
        long long brNech=k/2-(1-k%2);
        long long sbNech=brNech*(brNech+1);
        ans+=sbNech;
    }
    cout<<ans+1<<endl;
    return 0;
}
