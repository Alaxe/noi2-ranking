#include <iostream>
using namespace std;
int main(){
long long K, E, chislo, broq4=0, sbor=0, blizko=0, nomer=0, mp=200001;
cin>>K>>E;
while(sbor<=E && broq4<200){
   cin>>chislo;
   broq4++;
   if(chislo%2==0){
       sbor=sbor+chislo;
   }
   if(chislo>K){
       if(chislo-K<=mp){
            mp=chislo-K;
            nomer=broq4;
       }
   }else{
       if(K-chislo<=mp){
            mp=K-chislo;
            nomer=broq4;
       }
   }
}
cout<<nomer<<" "<<sbor<<endl;
return 0;
}
