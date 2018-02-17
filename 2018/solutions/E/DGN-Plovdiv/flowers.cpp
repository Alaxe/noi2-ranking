# include <bits/stdc++.h>
using namespace std;
int main ()
{
    long long n, q, maxi=0, br=0, i, a, suma=0, ans;
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>a;
        if (a>maxi)maxi=a;
        suma=suma+a;
    }
    cin>>q;
    br=(n*maxi)-suma;
    ans=br*q;
    cout<<ans<<endl;
    return 0;
}
