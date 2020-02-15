#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, maxn=0, br1=0, br2=0;
    cin>>n;
    char a;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(a=='a' || a=='b') br1++;
        else br2++;
        if(br1==br2) maxn=i;
    }
    cout<<maxn<<endl;
    return 0;
}
