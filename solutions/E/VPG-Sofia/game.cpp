#include <iostream>
using namespace std;
int main ()
{
    long long m, k, a, sum=0, nai_blizko_chislo, ans, t, i=2;
    bool flag=true;
    cin >> m >> k;
    cin >> a;
    if (a%2==0) sum+=a;
    nai_blizko_chislo=a-m;
    if (nai_blizko_chislo<0) nai_blizko_chislo=-nai_blizko_chislo;
    ans=1;
    if (sum>k or a==200) flag=false;
    while (flag) {
        cin >> a;
        if (a%2==0) sum+=a;
        t=a-m;
        if (t<0) t=-t;
        if (t<=nai_blizko_chislo) {
            nai_blizko_chislo=t;
            ans=i;
        }
        i++;
        if (sum>k or a==200) flag=false;
    }
    cout << ans << ' ' << sum << endl;
    return 0;
}
