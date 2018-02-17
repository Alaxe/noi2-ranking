#include<iostream>
using namespace std;
long long n,sbor=0;
int main(){
    cin>>n;
    for(long long i=n-1;i>0;--i){
        n*=i;
    }
    for(long long i=0;n>0;++i){
        sbor+=n%10;
        n/=10;
    }
    cout<<sbor;
    return 0;
}
