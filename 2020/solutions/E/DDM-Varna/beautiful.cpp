#include<iostream>
using namespace std;
int main()
{
    long long n, a, br = 0, numd = 11;
    cin >> n;
    for(a = 1; a <= n; a++)
    {
        if(a < 10) if(a % 1 == 0){ br++; }
        if(a < 100 && a > 10) if(a % 11 == 0){ br++; a = a + 9; }
        if(a < 1000 && a > 100) if(a % 111 == 0){ br++; a = a + 99; }
        if(a < 10000 && a > 1000) if(a % 1111 == 0) { br++; a = a + 999; }
        if(a < 100000 && a > 10000) if(a % 11111 == 0) { br++; a = a + 9999; }
        if(a < 1000000 && a > 100000) if(a % 111111 == 0) { br++; a = a + 99999; }
        if(a < 10000000 && a > 1000000) if(a % 1111111 == 0) { br++; a = a + 999999; }
        if(a < 100000000 && a > 10000000) if(a % 11111111 == 0) { br++; a = a + 9999999; }
        if(a < 1000000000 && a > 100000000) if(a % 111111111 == 0) { br++; a = a + 99999999; }
        if(a < 10000000000 && a > 1000000000) if(a % 1111111111 == 0) { br++; a = a + 999999999; };
        if(a < 100000000000 && a > 10000000000) if(a % 11111111111 == 0) { br++; a = a + 9999999999; }
        if(a < 1000000000000 && a > 100000000000) if(a % 111111111111 == 0) { br++; a = a + 99999999999; }
        if(a < 10000000000000 && a > 1000000000000) if(a % 1111111111111 == 0) { br++; a = a + 999999999999; }

    }
    cout << br << endl;
    return 0;
}
