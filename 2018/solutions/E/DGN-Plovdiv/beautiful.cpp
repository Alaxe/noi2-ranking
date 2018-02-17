# include <bits/stdc++.h>
using namespace std;
int main ()
{
    unsigned long long n, k, ans, i, chislo=1, remainder, maxi=9;
    cin>>n>>k;
    for (i=1;i<=n-1;i++)
    {
        chislo=chislo*10;
        maxi=maxi*10+9;
    }
    remainder=chislo%k;
    if (maxi<k)cout<<"NO"<<endl;
    else
    {
        if (remainder==0)cout<<chislo<<endl;
        else
        {
            ans=chislo+k-remainder;
            cout<<ans<<endl;
        }
    }
    return 0;
}
