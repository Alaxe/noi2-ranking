#include <iostream>
using namespace std;
int main(){
    long long n,k=1,chislo,br=0;
    cin>> n;
    while(chislo!=n){
    for(int i=0;i<k;i++){
        chislo=i+1;
       // cout<< chislo;
        br++;
        if(chislo==n) break;
        }
        for(int j=k;j>0;j--){
            if(j-1>0) br++;
       }
    k++;
  // cout<< endl;
   br++;
   if(chislo==n) break;
    }
    //cout<<  " " << chislo <<endl;
    if(br>1)cout<< br-1;
    else if(br==1) cout<< 1;






    return 0;
}


/*1
1121
121221321
1321232133214321
1432124321343
*/
