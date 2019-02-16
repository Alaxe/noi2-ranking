#include <bits/stdc++.h>
using namespace std;
int a[10001];
int n,umn=1,nok_=1;
void nok(){
    int kio=2;
    while(umn>1){
        while(umn%kio==0){
            for(int i=0;i<n;i++){
                if(a[i]%kio==0){
                    a[i]/=kio;
                    umn/=kio;
                }
            }
            nok_*=kio;
        }
        kio++;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    umn=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        umn*=a[i];
    }
    nok();
    ///cout<<nok_<<" ";
    int goshko=nok_,sq_goshko=1;
    while(true){
        goshko+=nok_;
        sq_goshko=sqrt(goshko);
        if(sq_goshko*sq_goshko==goshko){
            break;
        }
    }
    cout<<sq_goshko;
    return 0;
}
