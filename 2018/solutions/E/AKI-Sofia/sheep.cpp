#include <iostream>
using namespace std;
int main () {

long long n,l,a;
cin >> n >> l;
long long lipsvashti[l],gledano[n];
for (a=0;a<l;a=a+1) {
  cin >> lipsvashti[a];
}

 if (l=1 && lipsvashti[0]==1) {
 cout << (n+1)*2;
 }else{
   if (n<=10) {
   cout << n+1;
   } else if(n<20){
     cout << n+2;
     }
 }




return 0;
}
