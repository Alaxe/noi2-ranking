#include<iostream>
using namespace std;
int main(){
bool b=true;
long long n,k,ost,segChislo=10,del,pur=2,rez=10;
cin>>n>>k;
while(pur!=n){
pur++;
rez=rez*10;
}
while(segChislo/rez==0){
segChislo=segChislo*10;
}
ost=segChislo%k;
if(ost==0){
cout<<segChislo;
return 0;
  }else{
    while(b==true){
    segChislo=segChislo+k-ost;
      if(segChislo%k==0){
      cout<<segChislo;
      return 0;
      b=false;
      }
    }
  }
return 0;
}
