#include<iostream>

using namespace std;

int main ()
{
    int x,c1 = 0,c2 = 0,c3 = 0;
    long long n;
    cin >> n >> x;

    if(x == 0) {
        c1++;
    } else if (x == 1) {
        c2++;
    } else {
        c3++;
    }

    while(n) {
        if(n % 2 == 0) {
            swap(c2,c3);
        } else {
            swap(c2,c1);
        }
        n--;
    }
    if (c1 == 1) {
        cout << 0;
    } else if (c2 == 1) {
        cout << 1;
    } else {
        cout << 2;
    }

    cout << endl;
    return 0;
}
