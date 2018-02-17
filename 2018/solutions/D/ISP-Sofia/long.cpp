#include<iostream>

using namespace std;

long long pow(int a){
    long long ans=1;
    for(int i=1; i<a; i++){
        ans*=10;
    }
    return ans;
}

int main(){

    unsigned long long n, k, p, ost;
    cin >> n >> k;
    p=pow(n);

    ost=p%k;
    if(ost==0){
        ost=k;
    }

    cout << p+k-ost << '\n';

    return 0;
}
