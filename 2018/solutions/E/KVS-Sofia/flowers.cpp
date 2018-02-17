#include<iostream>
using namespace std;
int main(){
    long long n,q,i,nujni=0,nWis;
    cin>>n;
    long long wisochini[n];
    for(i=0;i<n;i++){
        cin>>wisochini[i];
    }
    cin>>q;
    nWis=wisochini[0];
    for(i=1;i<n;i++){
        if(wisochini[i]>=nWis){
            nujni+=i*(wisochini[i]-nWis);
            nWis=wisochini[i];
        }
        else{
            nujni+=nWis-wisochini[i];
        }
    }
    cout<<nujni*q;
return 0;
}
