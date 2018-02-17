#include<iostream>
using namespace std;
int main() {
    long long int a;
    cin>>a;
    long long int fac=1;
    for (long long int i=1 ; i<a ; i++) {
        fac*=i;
    }
    long long int sb=0;
    while (fac!=0) {
        sb+=fac%10;
        fac/=10;
    }
    cout<<sb<<endl;
        return 0;
}
