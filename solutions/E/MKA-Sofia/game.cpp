#include<iostream>
using namespace std;
int main () {
    long long M,K,chetni,sbor=0,nb,N=0,hffjcnkdn;
    cin>>M>>K;
    nb=10000;
    while(sbor<=K){
        cin>>chetni;
        N=N+1;
        if(chetni%2==0){
            sbor=sbor+chetni;
        }
        if(chetni>M&&chetni-M<=nb){
            nb=chetni-M;
            hffjcnkdn=N;
        }
        if(chetni<M&&M-chetni<=nb){
            nb=M-chetni;
            hffjcnkdn=N;
        }
    }
    cout<<hffjcnkdn<<" "<<sbor;
return 0;
}

