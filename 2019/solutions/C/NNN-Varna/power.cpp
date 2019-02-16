#include <bits/stdc++.h>
using namespace std;
int n, k;
int prneed[43], maxprneed=0;
void setprimes(int x)
{
    int j, tdn=0;
    while (x%2==0) tdn++, x/=2;
    if (tdn>prneed[2]) prneed[2]=tdn;
    if (prneed[2]>maxprneed) maxprneed=prneed[2];
    tdn=0;
    for (j=3; j<=x; j+=2)
    {
        while (x%j==0) tdn++, x/=j;
        if (tdn>prneed[j]) prneed[j]=tdn;
        if (prneed[j]>maxprneed) maxprneed=prneed[j];
        tdn=0;
    }
}
int cpwrfn(int x, int p)
{
    for (int i=1; i<p; i++)
    {
        x*=x;
    }
    return x;
}
int main()
{
    unsigned long long nn=1;
    int i, a;
    cin >> n >> k;
    for (i=0; i<n; i++)
    {
        cin >> a;
        setprimes(a);
    }
    for (i=0; i<43; i++)
    {
        if (prneed[i]) nn*=i;
    }
    if (maxprneed>k)
    {
        for (i=0; i<43; i++)
        {
            if (prneed[i]>k) nn*=cpwrfn(i, prneed[i]-k);
        }
    }
    cout << nn << endl;
}
