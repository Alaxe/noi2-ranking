#include<bits/stdc++.h>
using namespace std;

string d, t, step = "1";

string multLL_D(string a, char b)
{
    string rez;
    rez.resize(a.size() + 1, '0');
    int i, prenos = 0;
    for(i = a.size() - 1; i >= 0; i --)
    {
        int tmp = (a[i] - '0') * 2 + prenos;
        rez[i + 1] += tmp % 10;
        prenos = tmp / 10;
    }
    if(prenos)rez[i + 1] += prenos;
    while(rez[0] == '0')rez.erase(0, 1); step = rez;
    return rez;
}

int main()
{
    cin >> d; int i = 0;
    while(d != t)
    {
        i ++;
        t = t + multLL_D(step, '2');
    }
    cout << i << endl;
}
