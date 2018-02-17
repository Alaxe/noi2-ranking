#include<iostream>
using  namespace std;
int main (){
bool delise=false;
long long  pyr=1,n,k,br,gorpr;
cin>>n>>k;
for (br=1;br<n;br++) pyr=pyr*10;
for (gorpr=pyr*10;pyr<gorpr;pyr++) {
 if (pyr%k==0)  {
  cout<<pyr;
  delise=true;
    break;
 }
}
if (delise==false) cout<<"NO";

return 0;
}
