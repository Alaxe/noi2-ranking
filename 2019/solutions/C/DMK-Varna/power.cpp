#include <bits/stdc++.h>
using namespace std;
long long fun(long long a, long long st)
{
    long long i,j,rez=1;
    for (i=1;i<=st;i++)
    {
        rez*=a;
    }
    return rez;
}
int main()
{
    unsigned long long a,i,b,c,n,ch,k,del=1,d=2,br=0,rez=1;
    cin>>n>>k;
    for (i=0;i<n;i++)
    {
        cin>>ch;
        del=(del*ch)/(__gcd(del,ch));
    }
    while (del!=1)
    {
        if (del%d==0)
        {
            del/=d;
            br++;
        }
        else
        {
            if (br!=0)
            {
                if (br%k==0)
                {
                    br/=k;
                    br=fun(d,br);
                    rez*=br;
                }
                else
                {

                    br/=k;
                    br++;
                    br=fun(d,br);
                    rez*=br;

                }
            }
            d++;
            br=0;
        }
    }
    if (br!=0)
    {
        if (br%k==0)
        {
            br/=k;
            br=fun(d,br);
            rez*=br;
        }
        else
        {
            br/=k;
            br++;
            br=fun(d,br);
            rez*=br;
        }
    }
    cout<<rez<<endl;
}
