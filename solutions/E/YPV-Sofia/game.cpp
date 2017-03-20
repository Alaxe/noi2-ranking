#include<iostream>
using namespace std;
int main(){
    long long kris,eva,suma=0,nomer=1,diktuvano,razlika,minRazlika,nomerNaRazlikata=1;
    cin>>kris>>eva;
    while(nomer<200 && suma<eva){
        cin>>diktuvano;
        if(diktuvano%2==0){
            suma=suma+diktuvano;
        }
        if((diktuvano-kris)>0){
            razlika=diktuvano-kris;
        }else{
            razlika=kris-diktuvano;
        }
        if(razlika<=minRazlika || nomer==1){
            minRazlika=razlika;
            nomerNaRazlikata=nomer;
        }
        nomer++;
    }
    cout<<nomerNaRazlikata<<" "<<suma;
    cout<<endl;
return 0;
}
