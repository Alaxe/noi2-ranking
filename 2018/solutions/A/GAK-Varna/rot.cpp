#include<iostream>
using namespace std;

// 216
// 135
// 351

int desOtChislo(unsigned long long num) {

    int des = 1;
    while(num != 0) {
        num /= 10;
        des *= 10;
    }

    return des / 10;
}

unsigned long long rot(unsigned long long num) {
    int des = desOtChislo(num);
    int first = num / des;

    unsigned long long rotNum = num % des;
    rotNum = (rotNum*10) + first;

    return rotNum;
}

int main() {

    int noUsed;
    cin >> noUsed;

    unsigned long long M[4];
    cin >> M[0] >> M[1] >> M[2] >> M[3];

    for(int a = 0; a < 4; a++) {
        int turseno = 0;
        for(int i = 1; i<M[a]; i++) {
            if(rot(i) - i == M[a]) {
               turseno = i;
               break;
            }
        }
        cout << turseno << endl;
    }

    return 0;
}
