#include <iostream>
using namespace std;
int main () {
    char row[5000], temp, counter = 97;
    cin >> row;
    long long counter2 = 0;
    temp = row[0];
    for (int k = 0; k < 5000; k++) {
        if (row[k] > 122 or row[k] < 97) {
            break;
        }else {
            counter2++;
        }
    }
    for (int i  = 0;i < counter2; i++) {
        if (row[i] == temp and row[i + 1] == temp and row[i + 2] == temp) {
            row[i + 2] = counter;
            counter++;
        } else {
            temp = row [i + 1];
        }
    }
    cout << row <<endl;
    return 0;

}
