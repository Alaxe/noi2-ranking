#include <iostream>

using namespace std;

int main() {
    long long n, k, pw = 1;
    cin>>n>>k;

    bool cont = false;
    if(n > 2) {
    switch(k) {
    case 2:
    case 4:
    case 5:
    case 10:
        cout<<1;
        for(long long i = 0; i < n-1; i++)
            cout<<0;
        break;
    case 3:
    case 6:
        cout<<1;
        for(long long i = 0; i < n-2; i++)
            cout<<0;
        cout<<2;
        break;
    case 9:
    case 12:
        cout<<1;
        for(long long i = 0; i < n-2; i++)
            cout<<0;
        cout<<8;
        break;

    default:
        cont = true;
    }
    } else
        cont = true;

    if(cont) {
    for(long long i = 0; i < n-1; i++)
        pw *= 10;

    if(pw % k != 0)
        cout<<(((pw / k) + 1) * k);
    else
        cout<<pw;
    }

    cout<<endl;
}
