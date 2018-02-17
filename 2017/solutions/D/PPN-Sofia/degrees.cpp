#include<iostream>
#include<cstring>
using namespace std;

    long long vhod,cop;
    long long n=0,maxx=0;

int main() {

    cin >> vhod;
    cop=vhod;

    long long i=1;
    while(cop>0){
        cop=cop/10;
        i*=10;
    }
    cop=vhod;
    while(vhod!=0){
        n=0;
        while(cop>0 && cop%2==0){
            cop=cop/2;
            n++;
        }
        if(cop!=1){
            n=0;
        }

        if(n>maxx){
            maxx=n;
        }

        vhod=vhod%i;
        i/=10;
        cop=vhod;
    }

    cout << maxx << endl;

    return 0;
}
