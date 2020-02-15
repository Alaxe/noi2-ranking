#include<bits/stdc++.h>
using namespace std;
int n,a[100],dl,u,index1,index2,max1,max2,ans;
int main(){
    cin>>n>>dl>>u;
    for(int i = 0  ;i < n  ; ++ i){
        cin>>a[i];
        if(a[i]>=max1){
            max1=a[i];
            index1=i;
        }
    }
    for(int i = 0 ;  i < n ;  ++ i ){
        if(max2<=a[i] && a[i]!=max1){
            max2=a[i];
            index2=i;
        }
    }
    ans=max(index2,index1)-min(index2,index1);
    ans*=dl*max2;
    for(int i = 0 ; i < min(index2,index1); ++ i){
        ans+=dl*min(a[i],a[i+1]);
    }
    for(int i = max(index2,index1); i < n-1 ; ++i){
        ans+=dl*min(a[i],a[i+1]);
    }
    cout<<ans<<endl;
    return 0;
}

