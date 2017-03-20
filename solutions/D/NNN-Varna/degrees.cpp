#include <bits/stdc++.h>
using namespace std;
string mult2(string a)
{
    string rez;
    int i, tmp, prenos=0;
    for (i=a.size()-1; i>=0; i--)
    {
        tmp=(int)(a[i]-'0')+(int)(a[i]-'0')+prenos;
        prenos=tmp/10;
        rez=((char)(tmp%10+'0'))+rez;
    }
    if (prenos) rez=(char)(prenos+'0')+rez;
    return rez;
}
int main()
{
    string n, t, current="1";
    int i;
    cin >> n;
    if (n=="1")
    {
        cout << 0 << endl;
        return 0;
    }
    for (i=1; ; i++)
    {
        current=mult2(current);
        t+=current;
        if (t==n) break;
    }
    cout << i << endl;
}
