#include<iostream>

using namespace std;

int main ()
{
    long long n,r = 0;
    cin >> n;
    for(long long i = 1;i <= n;i++) {
        if (i <= 9) {
            r++;
        } else if (i <= 99 && i % 11 == 0){
            r++;
            i+= 10;
        } else if (i <= 999 && i % 111 == 0){
            r++;
            i+= 110;
        } else if (i <= 9999 && i % 1111 == 0){
            r++;
            i+= 1110;
        } else if (i <= 99999 && i % 11111 == 0){
            r++;
            i+= 11110;
        } else if (i <= 999999 && i % 111111 == 0){
            r++;
            i+= 111110;
        } else if (i <= 9999999 && i % 1111111 == 0){
            r++;
            i+= 1111110;
        } else if (i <= 99999999 && i % 11111111 == 0){
            r++;
            i+= 11111110;
        } else if (i <= 999999999 && i % 111111111 == 0){
            r++;
            i+= 111111110;
        } else if (i <= 9999999999 && i % 1111111111 == 0){
            r++;
            i+= 1111111110;
        } else if (i <= 99999999999 && i % 11111111111 == 0){
            r++;
            i+= 11111111110;
        } else if (i <= 999999999999 && i % 111111111111 == 0){
            r++;
            i+= 111111111110;
        } else if (i <= 9999999999999 && i % 1111111111111 == 0){
            r++;
            i+= 1111111111110;
        } else if (i <= 99999999999999 && i % 11111111111111 == 0){
            r++;
            i+= 11111111111110;
        } else if (i <= 999999999999999 && i % 111111111111111 == 0){
            r++;
            i+= 111111111111110;
        } else if (i <= 9999999999999999 && i % 1111111111111111 == 0){
            r++;
            i+= 1111111111111110;
        } else if (i <= 99999999999999999 && i % 11111111111111111 == 0){
            r++;
            i+= 11111111111111110;
        }
    }
    cout << r << endl;
    return 0;
}
