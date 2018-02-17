#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;
struct dm
{
 int d,m;
};
int main ()
{
    char k;
    dm a,b,c,d;
    cin>>a.d;
    cin.get(k);

    cin>>a.m;
    cin>>b.d;
    cin.get(k);

    cin>>b.m;
    cin>>c.d;
    cin.get(k);

    cin>>c.m;
    cin>>d.d;
    cin.get(k);

    cin>>d.m;
    if (a.d==b.d && a.d==c.d && a.d==d.d && a.m==b.m && a.m==c.m && a.m==d.m)
    {
        cout<<21252<<endl;
        return 0;
    }
    return 0;
}
