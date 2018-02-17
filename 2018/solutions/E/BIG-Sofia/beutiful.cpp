#include<iostream>
using namespace std;
int main(){
long long kolkoCifri;
cin>>kolkoCifri;
long long delitel,cifri[kolkoCifri],broqch,index,chislo=0,mnojitel=1,maxChislo;
bool deliLiSeNaDelitel=false;
cin>>delitel;
cifri[0]=1;
for(index=1;index<kolkoCifri;index++){
    cifri[index]=0;
}
for(index=kolkoCifri-1;index>=0;index--){
    chislo=chislo+cifri[index]*mnojitel;
    mnojitel=mnojitel*10;
}
maxChislo=chislo*9;
maxChislo=maxChislo+(maxChislo/9-1);
for(;!deliLiSeNaDelitel && chislo<=maxChislo;chislo++){
    if(chislo%delitel==0){
        deliLiSeNaDelitel=true;
        cout<<chislo;
    }
    if(chislo==maxChislo){
        cout<<"NO";
    }
}
return 0;
}
