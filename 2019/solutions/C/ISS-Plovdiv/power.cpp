#include <bits/stdc++.h>
using namespace std;
int main ()
{
    long long n, k, c=1, ck, br=0;
    cin>>n>>k;
    long long a[16384];
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    while (1!=0)
    {
        ck=1;
        for (int j=1; j<=k; j++)
            ck=ck*c;
        c++;
        for (int m=1; m<=n; m++)
            if (ck%a[m]==0)br++;
        if (br==n) break;
        br=0;
    }
    cout<<c-1<<endl;
    return 0;
}

