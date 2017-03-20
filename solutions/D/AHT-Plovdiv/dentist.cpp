#include <bits/stdc++.h>
using namespace std;
struct a
{
  long long t;
  int p;
};
int main()
{
    long long mi=999999,mii,i=0,mi2=9999;
    a a1[100];
    while(1==1)
    {
        cin>>a1[i].t>>a1[i].p;
        if(a1[i].t<mi)
        {
            mi=a1[i].t;
            mii=i;
        }
        if(a1[i].t<mi2&&a1[i].t>mi)
        {
            mi2=a1[i].t;
        }
        i++;
    }
    if(mi+a1[mii].p<mi2)
    return 0;
}
