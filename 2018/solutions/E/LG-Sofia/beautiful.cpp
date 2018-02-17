#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long n,k;
    cin>>n>>k;
    for(long long a=pow(10,(n-1));a<(pow(10,n));a++){
        if(a%k==0){
            cout<<a;
            break;
        }
    }

    return 0;
}
