#include<bits/stdc++.h>
using namespace std;
long long n,k,kolko=0,nakoired,podr;
long long sb_na_nech(long long int dok){
    if(dok%2==0){
        return (1+dok*2-1)*(dok/2);
    }else{
        return (1+(dok-1)*2-1)*((dok-1)/2)+dok*2-1;
    }
}
int main(){
    cin>>n>>k;
    kolko++;
    if(k==kolko){
        cout<<sb_na_nech(n-1)+n;
    }else{
        k--;
        if(k%2==0){
            nakoired=k/2+n;
            podr=2;
        }else{
            nakoired=k/2+1+n;
            podr=1;
        }
        if(podr==1){
            cout<<sb_na_nech(nakoired-1)+n;
        }else{
            cout<<sb_na_nech(nakoired-1)+(nakoired+(nakoired-n));
        }
    }
    cout<<endl;
    return 0;
}
