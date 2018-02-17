#include <iostream>
using namespace std;
int main () {
    long long int chislo[100000];
    long long int n = 0;
    long long int stepen = 1;
    for (int i = 0; ; ++i) {
        cin >> chislo[i];
        if (chislo[i] == stepen * 2) {
            ++n;
        }
        stepen = stepen * 2;
    }
    cout << n;


    return 0;
}
