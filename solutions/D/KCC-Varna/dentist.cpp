#include<bits/stdc++.h>
using namespace std;
struct kossyo
{
    int m;
    int t;
};
kossyo te[1003];
int i,n,p;
int cmp ( kossyo a, kossyo b )
{
    return a.m<b.m;
}
int main()
{
    i=0;
    while(1)
    {
        if (cin.eof()) break;
        cin >> te[i].m >> te[i].t;
        i++;
    }
    i--;
    sort(te,te+i,cmp);
    n=i;
    p=te[0].t;
    for ( i=1; i<n; i++ )
    {
        if ( (p+te[i-1].m)>te[i].m ) p=((te[i-1].m+p)-te[i].m)+te[i].t;
        else p=te[i].t;
    }
    cout << p << endl;
    return 0;
}
/**
55 15
185 22
130 10

0 30
720 10
715 20
714 25
*/
