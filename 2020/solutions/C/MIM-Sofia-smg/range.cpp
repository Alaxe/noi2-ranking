#include <bits/stdc++.h>
using namespace std;
int n,q;
int v[100000];
int f(int a,int b){
    int otg=0,st=0,en=0;
    for(int i=0;i<n;i++){
        if(v[i]>=a){
            st=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(v[i]<=b){
            en=i;
            break;
        }
    }
    otg=en-st+1;
    return otg;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v,v+n);
    cin>>q;
    int a,b;
    for(int i=0;i<q;i++){
        cin>>a>>b;
        if(v[0]>b or v[n-1]<a){
            cout<<"0\n";
        }else{
            cout<<f(a,b)<<"\n";
        }
    }
    return 0;
}
/**
6
9 1 3 10 3 4
3
1 4
9 12
15 20
**/
