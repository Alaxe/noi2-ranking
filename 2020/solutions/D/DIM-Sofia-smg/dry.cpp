#include<bits/stdc++.h>
using namespace std;
int a[104];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,u,v,ans=0;
    cin>>n>>u>>v;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=0;i<n-1;){
        int ng=a[i];
        int ngi=i;
        int ngs=a[i+1];
        int ngis=i+1;
        for(int j=i+1;j<n;++j){
            if(a[j]>ng){
                ng=a[j];
                ngi=j;
            }
            if(a[j]>ngs){
                ngs=a[j];
                ngis=j;
            }
            if(ng>a[i]){
                break;
            }
        }
        if(ngs==ng && ngi==ngis){
            ans+=u*v*(ngi-i)*min(a[i],ng);
            i=ngi;
        }else{
            ans+=u*v*(ngis-i)*min(a[i],ngs);
            i=ngis;
        }
        //cout<<ans<<" "<<ng<<" "<<ngi<<" "<<ngs<<" "<<ngis<<" "<<i<<endl;
    }
    cout<<ans<<"\n";
return 0;
}
