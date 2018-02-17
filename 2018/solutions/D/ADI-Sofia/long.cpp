#include<iostream>

using namespace std;

int main () {

    int n, k;
    long long i = 1;

    cin >> n >> k;

    while(n > 0){
        i *= 10;
        n --;
    }

    i /= 10;

    while(true){
        if(i % k == 0){
            cout << i;
            return 0;
        }

        i ++;
    }

    return 0;
}
