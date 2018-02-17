#include<iostream>
#include<cmath>
using namespace std;
long long int a,b;
void read() {
    cin>>a>>b;
}
int chf() {
    long long int d=9;
    for (long long int i=1 ; i<a ; i++) {
        d=d*10+9;
    }
        return d;
}
int chs() {
    long long int e=10;
    for (long long int i=2 ; i<a ; i++) {
        e*=10;
    }
        return e;
}
int ost() {
    long long int c=1;
    if (a>18) {
        for (long long int i=100000000000000000 ; i<999999999999999999 ; i++) {
            if (i%b==0) return i;
        }
    }
    else {
        for (long long int i=chs() ; i<chf() ; i++) {
            if (i%b==0) return i;
        }
    }
}
void print() {
    cout<<ost()<<endl;
}
int main() {
    read();
    print();
        return 0;
}
