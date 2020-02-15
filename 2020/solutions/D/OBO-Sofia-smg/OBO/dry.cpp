#include<bits/stdc++.h>
using namespace std;
int n,u,v;
int a[101],b[102][4],ngl=0,ngli=0,ngd=0,ngdi=0,otg=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>u>>v;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n-1;i++){
        if(a[i]>ngl){
            ngl=a[i];
            ngli=i;
        }
        b[i][0]=ngli;
        b[i][1]=ngl;
    }
    ngd=a[n-1];
    ngdi=n-1;
    for(int i=n-2;i>0;i--){
        b[i][2]=ngdi;
        b[i][3]=ngd;
        if(a[i]>ngd){
            ngd=a[i];
            ngdi=i;
        }
    }
    b[0][2]=ngdi;
    b[0][3]=ngd;
    for(int i=0;i<n-1;i++){
        otg+=min(b[i][1],b[i][3])*u*v;
    }
    cout<<otg<<endl;
    return 0;
}
