#include <iostream>
using namespace std;
int main() {
    long long k,n,m=4,i=0,gi=0,broi=0;
    bool dali=false;
    cin>>n>>k;
    for(m=1; dali==false; m++) {
        if(dali==true) {
            break;
        }
        for(i=1; i<m; i++) {

            broi++;
            if(i== n) {
                gi++;

            }
            if(gi==k) {
                dali=true;
                break;
            }
        }
        if(dali==true) {
            break;
        }
        for(i=m; i>0; i--) {

            broi++;
            if(i==n) {
                gi++;
            }
            if(gi==k) {
                dali=true;
                break;
            }
        }
        if(dali==true) {
            break;
        }

    }
    cout<<broi<<endl;
    return 0;
}
