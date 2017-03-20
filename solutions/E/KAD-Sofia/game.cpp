#include<iostream>
using namespace std;
int main(){
    int k,m;
    cin>>m>>k;
    int ch[200],i,sbor=0,razlika,naimalka=10000000,poz;
    for(i=0;i<200;i++){
            cin>>ch[i];
            if(ch[i]%2==0){
                    sbor=sbor+ch[i];
            }
            if(ch[i]>m){
                    razlika=ch[i]-m;
            }else{
                    razlika=m-ch[i];
            }
            if(razlika<=naimalka){
                    naimalka=razlika;
                    poz=i+1;
            }
            if(sbor>k){
                    break;
            }
    }
    cout<<poz<<" "<<sbor<<endl;
return 0;
}
