#include<iostream>
using namespace std;
int main(){
    long long n,nf=1,otg=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        nf=nf*i;
    }
    while(nf<100000000000000000){
        nf=nf*10;
    }
    for(int i=0;i<18;i++){
        if(i>0){
            nf=nf/10;
        }
        otg+=nf%10;
    }
    cout<<otg;
return 0;
}

