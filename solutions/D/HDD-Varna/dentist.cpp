#include <bits/stdc++.h>

using namespace std;

struct str
{
    int b, e;
};

str s[741];
queue<str> q;

bool cmp (str a, str b)
{
    return a.b < b.b;
}

int main()
{
    int m, i;

    i = 0;

    while (1)
    {
        cin >> s[i].b >> s[i].e;

        if (cin.eof())
            break;

        i ++;
    }

    sort (s, s + i, cmp);

    for (int j = 0; j < i; j ++)
    {
        q.push(s[j]);
    }

    int CurrT = 0, ResT = 0;
    str Curr;

    while (q.size())
    {
        Curr = q.front();
        q.pop();

         if (CurrT > Curr.b)
            CurrT += Curr.e;
        else
            CurrT = Curr.b + Curr.e;

        ResT = CurrT - Curr.b;
    }

    cout << ResT << endl;

    return 0;
}
/**
Vhod 1:
0 100
50 20
60 30
70 40

Izhod 1:
120

Vhod 2:
55 12
185 22
130 10

Izhod 2:
22

Vhod 3:
0 30
720 10
715 20
714 25

Izhod 3:
49

Vhod 4:
0 60
50 40

Izhod 4:
50

*/
