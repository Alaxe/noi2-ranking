#include<iostream>

using namespace std;

unsigned long long fact[25]={1};
long long sum[25];

int main(){

    int n;
    cin >> n;

    for(int i=1; i<25; i++){
        fact[i]=fact[i-1]*i;
    }

    for(int i=1; i<25; i++){
        while(fact[i]>0){
            sum[i]+=fact[i]%10;
            fact[i]/=10;
        }
    }

    cout << sum[n] << '\n';

    return 0;
}
