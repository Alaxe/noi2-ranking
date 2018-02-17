#include <iostream>
using namespace std;
int main(){
    long long n, q, i, ngv=0, brk=0;
    cin>>n;
    long long mm[n];
    for(i=n-1;i>=0;i=i-1){
        cin>>mm[i];
        if(ngv<mm[i]){
            ngv=mm[i];
        }
    }
    cin>>q;
    for(i=0;i<n;i=i+1){
        brk=brk+((ngv-mm[i])*q);
    }
    cout<<brk;
return 0;
}
