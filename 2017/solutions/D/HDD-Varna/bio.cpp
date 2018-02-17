#include <bits/stdc++.h>

using namespace std;

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    int df, mf, de, me, dp, mp, cd, cm, f, e, p, fe, fp, ep;
    char sl;

    cin >> df >> sl >> mf >> de >> sl >> me >> dp >> sl >> mp >> cd >> sl >> cm;

    f = e = p = 0;

    for (int i = 1; i < mf; i ++)
    {
        f += month[i];
    }
    f += df;

    for (int i = 1; i < me; i ++)
    {
        e += month[i];
    }
    e += de;

    for (int i = 1; i < mp; i ++)
    {
        p += month[i];
    }
    p += dp;

    f = f % 23;
    e = e % 28;
    p = p % 33;

    int i;

    for (i = 0; (23 * i + (f - p)) % 33 != 0; i ++);

    fp = 23 * i + f;

    for (i = 0; (23 * i + (f - e)) % 28 != 0; i ++);

    fe = 23 * i + f;

    for (i = 0; (28 * i + (e - p)) % 33 != 0; i ++);

    ep = 28 * i + e;

    int nod1, nod2;

    nod1 = 759;
    nod2 = 644;

    for (int i = 0; (759 * i + (fp - fe)) % 644; i ++);

    if (i * 759 + (fp - fe))
        cout << i * 759 + (fp - fe) << endl;
    else cout << 21252 << endl;

    return 0;
}
/**
Vhod 1:
1/1 1/1 1/1 1/1

Izhod 1:
21252

Vhod 2:
23/7 29/10 23/7 10/2

Izhod 2:
10789

*/
