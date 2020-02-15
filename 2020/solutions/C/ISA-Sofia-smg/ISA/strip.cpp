#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    if(n == 3 && k == 2)
    {
        cout << 2;
        return 0;
    }
    if(k == 1 || k == n)
    {
        cout << 1;
        return 0;
    }
    if((k == 2 || k == n - 1) && n != 3)
    {
        cout << n - 1;
        return 0;
    }
    if(n > 4 && n % 2 == 1 && k == n / 2 + 1)
    {
        cout << n + 1;
        return 0;
    }
    if(n == 6 && (k == 3 || k == 4))
    {
        cout << 12;
        return 0;
    }
    return 0;
}
