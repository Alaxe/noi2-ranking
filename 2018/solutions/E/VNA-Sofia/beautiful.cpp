#include<iostream>
#include<cmath>
using namespace std;

int main(){
long long cifreno,delitel,nMCifreno=0,chislo=0;
bool namerihLiChislo=false;
cin>>cifreno>>delitel;
    if(delitel!=1 or cifreno<3){
        nMCifreno=pow(10,(cifreno-1));


        for(long long i=0;namerihLiChislo==false and nMCifreno+i<nMCifreno*10;i++){
            if((nMCifreno+i)%delitel==0){
                namerihLiChislo=true;
                chislo=nMCifreno+i;
            }
        }
    }else {

        chislo=pow(10,cifreno-1);
        chislo++;
    }
if(chislo!=0){
cout<<chislo<<"\n";
}else if(chislo==0){
cout<<"NO\n";
}
return 0;
}
