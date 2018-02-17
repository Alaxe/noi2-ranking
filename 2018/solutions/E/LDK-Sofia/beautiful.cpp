#include <iostream>
using namespace std;
int main (){
    long long n,k,chislo=0,a=1,b,c=1;
    cin >> n >> k;
    for (int i = 0 ; i < n;i++){
          c= c * 10;
   }
   for (int i = 0 ; i < n-1;i++){
          a=  a * 10;
   }
   for (;a<c;a++){
         if (a % k == 0){
            chislo = a;
            break;
         }
   }
   if (chislo > 0){
   cout << chislo;
   }
   else {
    cout << "NO";
   }
return 0;
}
