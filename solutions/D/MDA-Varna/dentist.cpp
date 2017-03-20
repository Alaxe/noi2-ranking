#include <iostream>
#include <algorithm>
using namespace std;

int sz;
struct pacienti
{
    int d,l,ik;
};
pacienti p[721];
int cmp( pacienti a , pacienti b )
{
    return a.d < b.d;
}
void read()
{
    int i = 0;
    while( cin )
    {
        cin >> p[i].d >> p[i].l ;
        i ++ ;
    }
    sz = i ;
}
void solve()
{
    int i ;
    sort( p , p + sz , cmp );

    p[0].ik = p[0].d + p[0].l;

    for( i = 1 ; i < sz ; i ++ )
    {
        if( p[i].d > p[i-1].ik )
            p[i].ik = p[i].d + p[i].l;

        else
            p[i].ik = p[i-1].ik + p[i].l;
    }

    int ans;

    ans = p[sz-1].ik - p[sz-1].d ;

    cout << ans << endl;
}
int main()
{
    read();
    solve();
}
/*
55 15
185 22
130 10

0 30
720 10
715 20
714 25
*/
