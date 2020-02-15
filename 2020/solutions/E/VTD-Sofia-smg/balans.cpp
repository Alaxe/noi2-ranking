#include<iostream>
using namespace std;
int main(){
long long n,otrez=0,brA=0,brB=0,brC=0,brD=0,chislo=0;
cin>>n;
char cifri[n];
for(long long ia=0;n>ia;ia=ia+1){
    cin>>cifri[ia];
}
for(;chislo<=n-1;chislo=chislo+1){
    if(cifri[chislo]=='a'){
        brA=brA+1;
    }else{
        if(cifri[chislo]=='b'){
            brB=brB+1;
        }else{
            if(cifri[chislo]=='c'){
            brC=brC+1;
            }else{
                if(cifri[chislo]=='d'){
                    brD=brD+1;
                }
            }
        }
    }
    if(brA+brB==brC+brD){
        otrez=brA+brB+brC+brD;
    }
}
cout<<otrez;
return 0;
}
