#include <iostream>

using namespace std;

int length(int num) {if (num <= 9) {return 1;} else if(num <= 99){return 2;} else if(num <= 999) {return 3;} else if(num <= 9999) {return 4;} else if(num <= 99999) {return 5;} else if(num <= 999999) {return 6;} else if(num <= 9999999) {return 7;} else if(num <= 99999999) {return 8;} else if(num <= 999999999) {return 9;} else if(num <= 9999999999) {return 10;} else if(num <= 99999999999) {return 11;} else if(num <= 999999999999) {return 12;} else if(num <= 9999999999999) {return 13;} else if(num <= 99999999999999) {return 14;} else if(num <= 999999999999999) {return 15;} else if(num <= 9999999999999999) {return 16;} else if(num <= 99999999999999999) {return 17;} else if(num <= 999999999999999999) {return 18;} else {return 1;}}

int main() {
    int n, k;
    cin >> n >> k;
    int num = 0;
    while (num % k != 0 || length(num) < n) {
        num++;
    }

    if(length(num) < n) {
        cout << "NO!" << endl;
    }
    if(num % k != 0) {
        cout << "NO" << endl;
    } else {
        cout << num << endl;
    }


    return 0;
}
