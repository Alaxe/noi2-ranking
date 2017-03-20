#include <iostream>
using namespace std;

int main () {
    char A[160001];
    cin >> A;
    int n=1, i=0, last_digit=2, len=1;
    for (i; A[i+1]!='\0';) {
        last_digit = (last_digit*2)%10;
        if (A[i+len]==last_digit+'0') {n++; i+=len;}
        else {n++; i+=(len+1); len++;}
    }
    cout << n << endl;
    return 0;
}
