#include <iostream>
using namespace std;
int main (){
long long a,b,deliteliNaA=0,deliteliNaB=0,VsichkiDeliteli;
cin>>a>>b;
if(a%2){
   deliteliNaA=deliteliNaA+1;
   //cout<<deliteliNaA;
}
if(b%2){
   deliteliNaB=deliteliNaB+1;
   //cout<<deliteliNaB;
}
if(b%a){
    deliteliNaB=deliteliNaB+1;
}
VsichkiDeliteli=deliteliNaA+deliteliNaB;
cout<<VsichkiDeliteli;
return 0;
}
