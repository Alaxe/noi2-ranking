#include <iostream>
using namespace std;
int main () {
long long brc, brknac, obshtbrk=0, ngvis=0;
cin>>brc;
long long vis[brc], a;
a=brc;
for(brc;brc>0;brc--)
{
    cin>>vis[brc];
    if(vis[brc]>ngvis)
    {
        ngvis=vis[brc];
    }

}
cin>>brknac;
for(a;a>0;a--)
{
    obshtbrk=obshtbrk+((ngvis-vis[a])*brknac);
}
cout<<obshtbrk;


return 0;
}

