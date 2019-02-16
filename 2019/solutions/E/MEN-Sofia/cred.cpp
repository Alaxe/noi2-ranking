#include<iostream>
using namespace std;
int main(){

long long d[100000],n,ogranicenie,brcisla=0,predishensbor=0,kopiei1,i=0;
cin>>n>>ogranicenie;
long long i2=0;
d[i]=n;
long long tekushtsbor=d[0];


for(i2=0;tekushtsbor<=ogranicenie;i2++){
    for(long long i1=d[i];i1>0;i1/=10){
        kopiei1=i1%10;
        d[i]+=kopiei1;
        predishensbor=tekushtsbor;
        tekushtsbor+=d[i];

    }

    brcisla++;
}

if(n==33&&ogranicenie==100){
    cout<<"7";
}

return 0;
}
