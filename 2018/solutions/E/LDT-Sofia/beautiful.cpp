#include <iostream>
using namespace std;
int main(){
    long long n, k, vuzmOtg=1, vuzmOtgT=1, N;
    bool tvardeLiEGolqmo=false;
    cin>>n>>k;
    N=n;
    for(n=n;n>1;n=n-1){
        vuzmOtg=vuzmOtg*10;
    }
    for(vuzmOtg=vuzmOtg;tvardeLiEGolqmo==false;vuzmOtg=vuzmOtg+1){
        n=N;
        for(vuzmOtgT=vuzmOtg;n>0;n=n-1){
            vuzmOtgT=vuzmOtgT/10;
        }
        if(vuzmOtgT>0){
                tvardeLiEGolqmo=true;
                vuzmOtg=1;
        }
        if(vuzmOtg%k==0 and tvardeLiEGolqmo==false){
            tvardeLiEGolqmo=true;
        }
    }
    if((vuzmOtg-1)%k==0){
        cout<<vuzmOtg-1;
    }else{
        cout<<"NO";
    }
return 0;
}
