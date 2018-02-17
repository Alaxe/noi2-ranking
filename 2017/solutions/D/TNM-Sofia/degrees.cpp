#include <iostream>
using namespace std;
int digits(long long n){
    int i, x;
    for (i=1,x=0;i<n;i*=10){x++;}
    return x;
}
int digitstwo(long long n) {
    int i;
    long long N=1;
    for (i=0;i<n;i++){N*=2;}
    return digits(N);
}
int main(){
    long long n;
    int dig, i, x;
    cin >> n;
    dig=digits(n);
    for (i=1,x=0;dig>0;i++){
        dig-=digitstwo(i);
        x++;
    }
    cout << x << endl;
    return 0;
}
