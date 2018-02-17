#include<iostream>
using namespace std;
int main(){
    long long N,L,nomerche=0,r=0,p=0;
    bool edinici=false,desetici=false,stot=false,hil=false,desetohil=false,stohil=false,mil=false;
    cin>>N>>L;
    long long izgubeni[L];
    bool imaLi0=false;
    for(int i=0;i<L;i++){
        cin>>izgubeni[i];
    }
    for(int i=0;i<L;i++){
        if(izgubeni[i]==0){
            imaLi0=true;
        }
    }
    while(p<N){
        for(int j=0;j<L;j++){
            if((r+1)%10==izgubeni[j]){
                edinici=true;
                break;
            }
        }
        for(int j=0;j<L;j++){
            if((r+1)/10%10==izgubeni[j]){
                desetici=true;
                break;
            }
        }
        if(imaLi0 && r+1<10){
            desetici=false;
        }
        for(int j=0;j<L;j++){
            if((r+1)/100%10==izgubeni[j]){
                stot=true;
                break;
            }
        }
        if(imaLi0 && r+1<100){
            stot=false;
        }
        for(int j=0;j<L;j++){
            if((r+1)/1000%10==izgubeni[j]){
                hil=true;
                break;
            }
        }
        if(imaLi0 && r+1<1000){
            hil=false;
        }
        for(int j=0;j<L;j++){
            if((r+1)/10000%10==izgubeni[j]){
                desetohil=true;
                break;
            }
        }
        if(imaLi0 && r+1<10000){
            desetohil=false;
        }
        for(int j=0;j<L;j++){
            if((r+1)/100000%10==izgubeni[j]){
                stohil=true;
                break;
            }
        }
        if(imaLi0 && r+1<100000){
            stohil=false;
        }
        for(int j=0;j<L;j++){
            if((r+1)/1000000%10==izgubeni[j]){
                mil=true;
                break;
            }
        }
        if(imaLi0 && r+1<1000000){
            mil=false;
        }
        if(!edinici && !desetici && !stot && !hil && !desetohil && !stohil && !mil){
            nomerche=r+1;
            p++;
        }
        edinici=false;
        desetici=false;
        stot=false;
        hil=false;
        desetohil=false;
        stohil=false;
        mil=false;
        r++;
    }
    cout<<nomerche;
    return 0;
}
