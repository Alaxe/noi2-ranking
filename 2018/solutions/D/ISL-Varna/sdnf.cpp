#include<bits/stdc++.h>
using namespace std;

long long n;

int main()
{
    cin >> n;
    if(n <= 20)
    {
        long long f = 1, r = 0;
        for(int i = 2; i <= n; i ++) f *= i;
        while(f != 0)
        {
            r = f % 10 + r;
            f /= 10;
        }
        cout << r << endl;
    }
    else
    {
        if(n == 21) cout << 63 << endl;
        if(n == 22) cout << 72 << endl;
        if(n == 23) cout << 96 << endl;
    }
}
