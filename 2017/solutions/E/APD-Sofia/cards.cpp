#include <iostream>
using namespace std;
int main () {
    int n,br=1;
    cin>>n;
    int b=n*2;
    int a[b];
    for(int c=0; c<b; c++) {
        cin>>a[c];
    }
    for(int d=0; d<b; d=d+2) {
        if(a[d]>=a[d+2] and a[d+1]>=a[d+3] or a[d]>=a[d+3] and a[d+1]>=a[d+2]) {
            br++;
        }
    }
    cout<<br<<endl;
    return 0;
}
