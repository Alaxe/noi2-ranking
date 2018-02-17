#include<iostream>

using namespace std;

int main () {

    int n;
    cin >> n;

    unsigned long long fact = 1, sum = 0;

    for(int i = n ; i > 0; i --){
        fact *= i;
    }

    cout << fact << "\n";

    while(fact > 0){
        sum += fact % 10;

        fact /= 10;
    }

    cout << sum << "\n";

    return 0;
}
