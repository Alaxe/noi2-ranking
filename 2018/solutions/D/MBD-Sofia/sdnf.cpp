#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    float bignum=1;
    for(int a=1;a<=n;a++){
        bignum=bignum*a;
    }
    int gol=0;
    for(int a=bignum;a>0;a=a/10){
        gol=gol+a%10;
    }
    cout << gol << endl;
    return 0;
}
