#include<iostream>
using namespace std;
int main(){
long long brcvetq,a;
cin>>brcvetq;
long long visochina[brcvetq],kapkizamil,maximalno=0,b,minkapki=0;
for(a=0;a<brcvetq;a++){
    cin>>visochina[a];
    if(visochina[a]>maximalno){
      maximalno=visochina[a];
    }
}
cin>>kapkizamil;
for(b=0;b<brcvetq;b++){
    minkapki=(maximalno-visochina[b])*kapkizamil+minkapki;
}
cout<<minkapki;
return 0;
}
