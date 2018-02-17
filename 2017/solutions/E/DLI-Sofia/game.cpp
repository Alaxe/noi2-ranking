#include<iostream>
using namespace std;
int main (){

long long k,e,suma,chisla[201],razlika=999999999999999999,vagennomer,s;
cin>>k>>e;
suma=0;
for( s=1;s<200;s=s+1){
    cin>>chisla[s];
    if(chisla[s]%2==0){
        suma=suma+chisla[s];
    }
    if(chisla[s]>k){
        if(razlika>=chisla[s]-k)
        {
            razlika=chisla[s]-k;
            vagennomer=s;
        }
    }
          else{ if(razlika>=k-chisla[s])
          {
              razlika=k-chisla[s];
              vagennomer=s;
          }}
if(suma>e){s=300;}}



cout<<vagennomer<<" "<<suma;

return 0;
}
