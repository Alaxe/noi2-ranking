#include<iostream>
using namespace std;
long long br,deb,shir,vis[1001],i,obem=0,nobemi=0,sbor=0,zaek[1001];
int main(){

    cin>>br>>deb>>shir;
    for(i=0;i<br;i++){
        cin>>vis[i];
    }
    for(i=0;i<br;i++){
            if(vis[i]>vis[i+1]){
                if(vis[i+1]<vis[i+2]){
                    if(vis[i]<vis[i+2]){
                        obem=vis[i]*(deb*2)*shir;
                    }else{
                        obem=vis[i+2]*(deb*2)*shir;

                    }
                }
            }
            if(vis[i]>=vis[i-1]&&vis[i]<=vis[i+1]){
                nobemi=vis[i]*shir*deb;
            }

        sbor=nobemi+obem+vis[0]*shir*deb;
    }
    cout<<sbor<<endl;
return 0;
}
