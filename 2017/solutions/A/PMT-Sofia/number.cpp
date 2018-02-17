#include <iostream>
#include <cmath>
using namespace std;

unsigned long long m, n, l, r;

int main(){
    cin >> m >> n;
    l = sqrt(m);
    if(l*(l+1) < m)
        l++;
    if(l*(l+1) > n){
        cout << 0;
        return 0;
    }
    r = sqrt(n);
    if(r*(r+1) < m){
        cout << 0;
        return 0;
    }
    if(r*(r+1) <= n)
        r++;

    cout << r-l;
    return 0;
}
