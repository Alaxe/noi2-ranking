#include <bits/stdc++.h>

using namespace std;

string sum_LL(string a, string b)
{
    int tmp, ost;

    ost = 0;

    for (int i = a.size() - 1; i >= 0; i --)
    {
        tmp = (a[i] - '0') + (b[i] - '0') + ost;

        ost = tmp / 10;
        a[i] = (tmp % 10) + '0';
    }

    if (ost)
    {
        a = (char)(ost + '0') + a;
    }

    return a;
}

int main()
{
    string s, s1, p;
    int n;

    cin >> s;

    p = "2";
    s1 = "";
    n = 0;

    while (s1.size() < s.size())
    {
        s1 += p;
        n ++;

        p = sum_LL(p, p);
    }

    cout << n << endl;

    return 0;
}
/**
Vhod 1:
2481632641282565121024204840968182163643272865456

Izhod 1:
16

Vhod 2:
2481632

Izhod 2:
5

Vhod 3:
248163264128256512

Izhod 3:
9

Vhod 4:
2

Izhod 4:
1

*/
