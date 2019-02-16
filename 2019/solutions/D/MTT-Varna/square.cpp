#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
unsigned long long a[10008];
bool kv[7];
int square (int num)
{
    for (int i=1; i*i<=num; i++) if (i*i==num) return i;
    return 0;
}
int nepovtorim (int koren)
{
    if (koren== 1 || koren==5 || koren==6) return koren;
    if (koren==2)
    {
        if (!kv[4] && !kv[6]) return koren;
        else return 0;
    }
    if (koren==3)
    {
        if (!kv[6]) return koren;
        else return 0;
    }
    if (koren==4)
    {
        if (!kv[6]) return koren;
        else return 2;
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie (0);
    cout.tie(0);
    unsigned long long n, nok=0, sq, nep;
    cin >> n;
    cin >> a[0];
    nok=a[0];
    for (int i=1; i<n; i++)
    {
        cin >> a[i];
        nok=nok*a[i]/__gcd(nok, a[i]);
    }
    sort (a, a+n);
    for (int i=n-1; i>=0; i--)
    {
        sq=square(a[i]);
        nep=nepovtorim(sq);
        if (sq && !kv[sq] && nep)nok/=nep, kv[nep]=true;
    }
    cout << nok << endl;
    return 0;
}
