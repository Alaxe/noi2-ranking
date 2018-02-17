#include<iostream>
using namespace std;
long long n,k,a=1;

int main(){
    cin>>n>>k;
    for(long long i=0;i<n-1;++i){
        a*=10;
    }
    while(a%k!=0){
        ++a;
    }
    cout<<a;
    return 0;
}
