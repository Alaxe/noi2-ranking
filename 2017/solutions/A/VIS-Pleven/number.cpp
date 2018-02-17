#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long n, m;
    cin >> m >> n;
    //n = 954345456324842426;
    //m = 548435486213785365;
    long long m1 = (int)sqrt(m);
    long long n1 = (int)sqrt(n);
    long long cnt = 0;
    if (m1 * (m1 + 1) >= m)
    {
        cnt++;
    }
    if (n1 * (n1 + 1) <= n)
    {
        cnt++;
    }
    m1++;
    n1--;
    cnt += n1 - m1 + 1;
    cout << cnt << endl;

    return 0;
}
