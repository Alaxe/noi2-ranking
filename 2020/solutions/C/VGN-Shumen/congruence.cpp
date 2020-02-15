#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
const int MAXN = 15000000;
struct el
{
    char c;
    int ind;
};
el a[MAXN];
char ans[MAXN];
int len = 0, p;
bool cmp(el n, el m)
{
    if(n.c < m.c) return true;
    if(n.c > m.c) return false;
    return n.ind < m.ind;
}
void read()
{
    while(cin >> a[len].c)
    {
        a[len].ind = len;
        len++;
    }
    len;
    sort(a, a+len, cmp);
}
void solve()
{
    ans[a[0].ind] = 'A';
    int l = 0;
    for(int i=1; i<len; i++)
    {
        if(a[i].c == a[i-1].c)
        {
            ans[a[i].ind] = ans[a[i-1].ind];
        }
        else
        {
            l++;
            ans[a[i].ind] = char(ans[a[i-1].ind]+1);
        }
    }
    l++;
    p = 26-l;
}
void print()
{
    for(int i=0; i<len; i++)
    {
        cout << ans[i] ;
        ans[i] = (char)(ans[i]+p);
    }
    cout << endl;
    for(int i=0; i<len; i++)
    {
        cout << ans[i] ;
    }
    cout << endl;
}
int main()
{
	read();
	solve();
	print();
    return 0;
}
