#include <iostream>

uint64_t power(uint64_t num, int pow);
inline bool checkDivisible(uint64_t num, int a);

int main()
{
    int n, k;
    std::cin >> n >> k;
    int a[n];
    for(int i=0; i<n; i++) std::cin >> a[i];

    int c = 0;
    bool f = false;
    while(!f) {
        c++;
        uint64_t b = power(c, k);
        f = true;
        for(int i = 0; i < n; i++) {if(!checkDivisible(b, a[i])) f = false;}
    }

    std::cout << c << '\n';

    return 0;
}

uint64_t power(uint64_t num, int pow) {
    uint64_t result = 1;
    for(int i = pow; i > 0; i--) {
        result *= num;
    }
    return result;
}

inline bool checkDivisible(uint64_t num, int a){

    if(!(num%a)) return true;
    return false;

}
