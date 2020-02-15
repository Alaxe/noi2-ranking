#include<iostream>
using namespace std;
int main (){

int n,u,v,vis[100],l=0;

cin>>n>>u>>v;

for(int i=0;i<n;i++){
    cin>>vis[i];
}

for(int i=0;i<n-1;i++){
    if(vis[i]<vis[i+1] && vis[i]<vis[i-1] && i!=0){
        if(vis[i-1]>vis[i+1]){
            l+=2*u*v*vis[i+1];
        }else{
            l+=2*u*v*vis[i-1];
        }
    }else{
        if(vis[i]<=vis[i+1]){
            l+=u*v*vis[i];
        }
        if(vis[i]>vis[i+1] && vis[i+2]<=vis[i+1]){
            l+=u*v*vis[i+1];
        }
    }
}

cout<<l;

return 0;
}
