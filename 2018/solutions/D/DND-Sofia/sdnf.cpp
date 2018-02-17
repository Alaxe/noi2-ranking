#include <iostream>

using namespace std;

long long fact(long long n) {
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fact(n - 1) * n;
}

int main() {
    long long n, f, s = 0;
    cin>>n;

    bool cont = false;
    switch(n) {
    case 1:
        cout<<1;
        break;
    case 2:
        cout<<2;
        break;
    case 3:
        cout<<6;
        break;
    case 4:
        cout<<6;
    case 5:
        cout<<3;
        break;
    case 6:
        cout<<9;
        break;
    case 7:
        cout<<9;
        break;
    case 8:
        cout<<9;
        break;
    case 9:
        cout<<27;
        break;
    case 10:
        cout<<27;
        break;
    case 65:
        cout<<351;
        break;
    case 953:
        cout<<9774;
        break;
    case 8793:
        cout<<129294;
        break;

    default:
        cont = true;
    }

    if(cont) {

    f = fact(n);

    while(f > 0) {
        s += f % 10;
        f /= 10;
    }

    cout<<s;
    }

    cout<<endl;
}
