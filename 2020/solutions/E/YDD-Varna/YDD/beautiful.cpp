#include <bits/stdc++.h>
using namespace std;
int main ()
{
    long long n, br, q, p, k=0, st, del;
    cin >> n;
    for (long long i=1 ; i <= n ; i++)
    {
        br=0;
        q=i;
        while (i > 0)
        {
            i = i/10;
            br++;
        }
        i=q;
        long long c[br];
        del = 1;
        for (long long a = 1 ; a < br ; a++)
        {
            del *= 10;
        }
        p=1;
        while (p <= br)
        {
            c[p-1] = i/del%del;
            del/=10;
            p++;
        }
        c[br-1] = i%10;
        st = 0;
        p=1;
        while (p < br+1)
        {
            if (c[p] == c[p-1]) st++;
            p++;
        }
        if (st == br-1) k++;
    }
    cout << k << endl;
    return 0;
}
