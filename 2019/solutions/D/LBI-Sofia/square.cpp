#include <iostream>
using namespace std;
int main() {
    bool dali=true;
    long long n,i=0,k=0;
    cin>>n;
    long long chis[n];
    for(i=0; i<n; i++) {
        cin>>chis[i];
    }
    for(k=1; true; k++) {
        dali=true;
        for(i=0; i<n; i++) {
            if((k*k)%chis[i]==0) {
                dali=true;
            } else {
                dali=false;
                break;
            }
        }
        if(dali==true) {
            break;
        }
    }
    cout<<k<<endl;
    return 0;
}
