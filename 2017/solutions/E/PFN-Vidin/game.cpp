#include <iostream>
using namespace std;
int main(){

    int K, M;
    cin >> M >> K;
    int even = 0, num, countnums, nexttok, mqstointherow;

    while ((countnums != 200) || (even < K)){
        cin >> num;
        mqstointherow += 1;
        countnums += 1;
        if (num % 2 == 0){
            even += num;
        }
        if (num == M-1 || num == M-2 || num == M-3 || num == M+1 || num == M+2 || num == M+3) {
            nexttok = num;
            continue;

    }
        if (even > K){
            break;
        }


    }

    cout << nexttok << " " << even << endl;

    return 0;
}
