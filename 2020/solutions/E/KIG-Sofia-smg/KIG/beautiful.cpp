#include<iostream>
using namespace std;
int main(){
    long long n,a=100,j=11,br=0;
    cin>>n;
    for(long long i=1;i<=n;i++){
        if(i<10){
            br++;
        }
        if(i<a && i>a/10 && i%j==0){
            br++;
        }
        if(i==a){
            j+=a;
            a*=10;
        }
    }
    cout<<br;
    return 0;
}
