#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
string to_string(long long n){
    ostringstream ostr;
    ostr<<n;
    return ostr.str();
}
int main(){
    unsigned long long cifri, delimo;
    cin>>cifri>>delimo;
    if(cifri < 19){
            int n = cifri - 1;
            unsigned long long kolko = pow(10, n);
            if(kolko % delimo == 0){
                    cout<<kolko<<endl;
                    return 0;
            }
            kolko /= delimo;
            cout<<delimo*(kolko + 1);
    }else{
        if(delimo == 2 || delimo % 10 == 0 || delimo % 5 == 0 || delimo == 4){
                cout<<"1";
                for (long long i=0; i<cifri - 1; i++){
                        cout<<"0";
                }
    }
    }

    return 0;
}

