#include<iostream>
using namespace std;
long long razmer1[1000000],razmer2[1000000];
int main(){
long long n;
long long b=0;
cin>>n;
long long broqch,broqch2,broqch3=0,naidulgaredica=0,redica=0;
for(broqch=0;broqch<n;broqch++){
    cin>>razmer1[broqch]>>razmer2[broqch];
}
for(broqch2=0;broqch2<n;broqch2++){
    if(razmer1[broqch3]>=razmer1[broqch3+1] and razmer2[broqch3]>=razmer2[broqch3+1]){
        b=2;
    }else{b=0;}
    if(razmer1[broqch3]>=razmer2[broqch3+1] and razmer2[broqch3]>=razmer1[broqch3+1]){
        b=2;
    }else{b=0;}
    if(b==2){
        redica++;
    }
    if(redica>naidulgaredica){
        naidulgaredica=redica;
    }
    broqch3++;
}
cout<<naidulgaredica;
return 0;
}
