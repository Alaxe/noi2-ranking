#include<iostream>
using namespace std;
int main()
{
    long long n, a, b, ma, mb, s, ms, br = 0, mmax;
    cin >> n;
    cin >> a >> b;
    ma = a;
    mb = b;
    s = a * b;
    ms = s;
    mmax = ma;
    if(mmax<mb)
        mmax = mb;
    for(long long i = 1; i <= n-1; i++)
    {
        cin >> a >> b;
        s = a*b;
        if(ms>=s&&mmax>=a&&mmax>=b)
        {
            br++;
            mmax = ma;
        if(mmax<mb)
            mmax = mb;
        }
        ma = a;
        mb = b;
        ms = s;
    }
    if(ms>=s&&mmax>=a&&mmax>=b)
        {
            br++;
            mmax = ma;
        if(mmax<mb)
            mmax = mb;
        }
    if(br!=0)
        cout << br+1 << endl;
    else
        cout << br << endl;
    return 0;
}
