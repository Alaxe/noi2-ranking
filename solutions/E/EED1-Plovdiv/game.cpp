#include <iostream>
using namespace std;

int main()
{
    int k,m,sbor;
    int ma1;
    int min1 = 1;
    sbor = 0;
    cin >> m >> k;
    int a;
    while (a != 200 && sbor <= k);
    {
        cin >> a;
        if (a % 2 == 0) sbor = sbor + a;
        if (sbor >= k) break;
        ma1 = a - m;
        if (min1 > ma1) min1 = a;
    }
    cout << min1 << " " << sbor << endl;
}
