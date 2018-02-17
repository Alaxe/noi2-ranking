#include <iostream>
using namespace std;
int main(){
    long long n, l, i, segCh, segChT;
    bool sadurzhaLiIzgubenPechat=false;
    cin>>n>>l;
    long long p[l];
    for(i=l-1;i>=0;i=i-1){
        cin>>p[i];
    }
    for(segCh=1;n>0;segCh=segCh+1){
        sadurzhaLiIzgubenPechat=false;
        for(segChT=segCh;segChT>0 and sadurzhaLiIzgubenPechat==false;segChT=segChT/10){
            for(i=l-1;i>=0 and sadurzhaLiIzgubenPechat==false;i=i-1){
                if(segChT%10==p[i]){
                    sadurzhaLiIzgubenPechat=true;
                }
            }
        }
        if(sadurzhaLiIzgubenPechat==false){
            n=n-1;
        }
    }
cout<<segCh-1;
return 0;
}
