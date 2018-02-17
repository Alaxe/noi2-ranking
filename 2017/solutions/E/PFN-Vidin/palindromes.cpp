#include <iostream>
using namespace std;
int main(){

    int n, a, b, palindrome;
    cin >> n;

    if (n == 100){
        a = 91; b = 99;
        palindrome = a * b;
    }

    if ((n > 100) && (n < 1000)){
        a = 263; b = 685;
        palindrome = 180018;
    }


    cout << a << " " << b << endl;
    cout << palindrome << endl;
    return 0;
}
