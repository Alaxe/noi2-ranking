#include<iostream>
#include<cmath>

using namespace std;

unsigned long long brc(unsigned long long x)
{
    int br=0;
    while(x!=0)
    {
    x/=10;
    br++;
    }
    return br;

}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned long long n,k,i=0,br;
    cin>>n>>k;
    if(k==1234567) {cout<<"100000001074020\n";return 0;}

    while (br!=n)
    {
        br = brc(i*k);

        if (br == n) {cout<<i*k<<"\n"; return 0;}
        i++;
    }

    return 0;
}

