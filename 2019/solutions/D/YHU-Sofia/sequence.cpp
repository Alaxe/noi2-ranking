#include<iostream>
using namespace std;
int main(){
long long chis,put;
cin>>chis>>put;
if(put==1){
  cout<<chis*(chis-1)+1;
}else if(put%2==0){
  cout<<(chis+put/2)*(chis-1+put/2)+1-((chis+put/2)-chis);
}else {
  cout<<(chis+put/2)*(chis-1+put/2)+1+((chis+put/2)-chis);
}

return 0;
}
