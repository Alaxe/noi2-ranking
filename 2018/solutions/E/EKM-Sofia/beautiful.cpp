#include <iostream>
using namespace std;
int main(){

long long n,k,chislo=1,naiMalkoChislo,index,granica=1;
bool namerihLiChislo=false;
cin>>n>>k;
for(index=0;index<=n;index=index+1){
    granica=granica*10;
}
for(index=1;index<n;chislo=chislo*10){
    index=index+1;
}
for(;chislo<granica;chislo=chislo+1){
    if(chislo%k==0&&chislo<naiMalkoChislo){
        naiMalkoChislo=chislo;
        namerihLiChislo=true;
    }
}
if(namerihLiChislo==false){
    cout<<"NO";
}else{
    cout<<naiMalkoChislo;
}

return 0;
}
