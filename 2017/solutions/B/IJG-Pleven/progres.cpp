#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
long long n, ok, br, a[1100];
int main ()
{
    cin>>n;
    for (int i=1; i<=n; i++)
         cin>>a[i];
    for (int i=2; i<=n; i++)
        if (a[i]-a[i-1]>0) ok++;
    if (ok==n-1)
    {
        ok=0;
        br=(br+1)%123456789012345;
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=i+1; j<=n; j++)
        {
            if (a[j]-a[i]>0)
            {
                br=(br+1)%123456789012345;
                ok++;
            }
            if(ok>1 && a[j]-a[i]<0)
            {
                ok=0;
                br=(br+1)%123456789012345;
            }
        }
    }
    cout<<br%123456789012345<<endl;
    return 0;
}
