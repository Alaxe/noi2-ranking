#include<iostream>
using namespace std;
int main(){
    long k, mb = 0, cmb;
    cin>>k;
    long x[k], y[k];
    for(long c=0;c<k;c++) cin>>x[c]>>y[c];
    for(long c=0;c<k;c++){
        cmb=0;
        for(long n=c+1;n<k;n++){
            if(((x[n-1]>=x[n]&&y[n-1]>=y[n])||(x[n-1]>=y[n]&&y[n-1]>=x[n]))||((x[n-1]>=x[n]&&y[n-1]>=y[n])&&(x[n-1]>=y[n]&&y[n-1]>=x[n]))){
                cmb++;
            } else {
                break;
            }
        }
        if(cmb>mb) mb = cmb;
    }

    cout<<mb+1;

    return 0;
}
