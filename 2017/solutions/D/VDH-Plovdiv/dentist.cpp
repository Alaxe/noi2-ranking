#include <iostream>
#include <algorithm>
using namespace std;
struct t
{
    int a;
    int b;
    int c;
};
bool cmp(t a, t b)
{
    if (a.a>b.a) return 0;
}
int main()
{
    t m[10000];
    int i=0, n;
    while (cin>>m[i].a>>m[i].b) i++;
    n=i+1;
    sort(m, m+n, cmp);
    m[0].c=m[0].a+m[0].b;
    for (int i=1; i<n; i++)
    {
        m[i].c=max(m[i].a, m[i-1].c)+m[i].b;
    }
    cout<<m[n-1].c-m[n-1].a<<endl;
}
