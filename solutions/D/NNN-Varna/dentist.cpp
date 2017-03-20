#include <bits/stdc++.h>
using namespace std;
struct pacient
{
    int c;
    int f;
};
pacient p[1000000];
bool cmp(pacient a, pacient b);
int main()
{
    int i, n, t=0;
    for (i=0; ; i++)
    {
        if (cin.eof()) break;
        cin >> p[i].c >> p[i].f;
    }
    n=i-1;
    sort (p, p+n, cmp);
    for (i=0; i<n; i++)
    {
        if (t<p[i].c) t=p[i].c;
        t+=p[i].f;
    }
    cout << t-p[n-1].c << endl;
}
bool cmp(pacient a, pacient b)
{
    if (a.c==b.c) return a.f<b.f;
    return a.c<b.c;
}
