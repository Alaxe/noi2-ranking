#include <iostream>
using namespace std;
long long b[100003],otg[100003];
int main(){
    long long n;
    cin>> n;
    for(long long i=n-1;i>=0;i--){
        otg[i]=i+1;
        //cout<< "otg=" << otg[i] << endl;
    }
    for(long long i=0;i<n;i++){
        cin>> b[i];
    }
    for(long long i=0;i<n;i++){
        for(long long j=i+1;j<n-1;j++){
                //cout<< b[j] << " " << b[j+1] << " ";
            if(b[j]>b[j+1]){
                if(otg[j]>otg[j+1]) swap(otg[j],otg[j+1]);
                //cout<< "yes";
            }else if(otg[j]>otg[j+1]) swap(otg[j],otg[j+1]);
            //cout<< endl;
        }
    }
    for(long long i=0;i<n;i++){
        if(i>0) cout<< " ";
        cout<< otg[i];
    }



    return 0;
}

