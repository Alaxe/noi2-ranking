#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#define int_t unsigned long long
using namespace std;

bool composite(int_t a) {
    for(int_t i = 2; i < sqrt(a); i++) {
        if(a % i == 0) {
            return true;
        }
    }
    return false;
}

int_t limit(int_t n) { //0??
    int_t digits = 0;
    while(n) {
        n /= 10;
        digits++;
    }
    n = 1;
    for(int_t i = 0; i < digits + 1; i++)
        n *= 10;
    return n;
}

int main() {
    int_t n;
    cin >> n;
    n += 2-n%3;
    int_t lim = limit(n);
    for(int_t i = n; i < lim; i+=6) {
        if(composite(9 + i)) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
	return 0;
}
