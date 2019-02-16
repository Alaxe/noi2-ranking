#include <iostream>
using namespace std;
int main() {
int  n;
int br;
int k;
cin>>n>>k;
if(n==1 && k==1)cout<<1;
else{
br=n;
    for(int i=1;i<n;i++){
    br+=i;
    }
    br+=n-2;
    if(n>=4){
    br+=n-3;
}
if(n==k){
    cout<<br*2;
}
if(k==1){
    cout<<br;
}
}
}
