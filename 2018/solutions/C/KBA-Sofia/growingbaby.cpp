#include<iostream>
using namespace std;
void slagai(nmp) {
    nmp+=p;
}
void neSlagai(nmp) {

}
int main() {
    long long nmp;
    long long n,p,q;
    long long broiHraneniq,broiSraneniq;
    long long maksimumHraneniq,minimumHraneniq;
    unsigned long long izhod=0;
    cin>>nmp>>n>>p>>q;
    n-=nmp;
    maksimumHraneniq=(n-p)/(p-q)+1;
    if((n-p)%(p-q)!=0) {
        maksimumHraneniq++;
    }
    minimumHraneniq=n/p;
    if(n%p!=0) {
        minimumHraneniq++;
    }
    broiHraneniq=minimumHraneniq;
    broiSraneniq=0;
    izhod++;
    while(true) {
        nmp=0;
        while(nmp<60) {
            nmp+=p;
        }
        while(broiSraneniq<broiHraneniq) {
            if(broiHraneniq*p-broiSraneniq*q<n) {
                break;
            } else {

            }
            broiSraneniq++;
        }
        broiHraneniq++;
    }
    cout<<izhod;
    return 0;
}
