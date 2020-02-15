#include <iostream>

int f(int a){
    int result = 1;
    for(int i = 2; i <= a; i++) {
        result *= i;
    }
    return result;
}

int main (){
    int n, k;
    std::cin >> n >> k;

    std::cout << (f(n - 1) / f((n - 1) - (n - k))) / f(n - k) << std::endl;
    return 0;
}
// 5 2
// 5 1 2 3 4
// 4 1 2 3 5
// 3 1 2 4 5
// 2 1 3 4 5
// C(4, 3) = (4! / (4 - 3))! / 3! = (4 * 3 * 2) / 6 = 4

// 5 3
// 5 4 1 2 3
// 5 3 1 2 4
// 4 3 1 2 5
// 5 2 1 3 4
// 4 2 1 3 5
// 3 2 1 4 5
// C(4, 2) = (4! / (4 - 2)!) / 2! = (4 * 3) / 2 = 6
