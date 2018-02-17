#include <bits/stdc++.h>
using namespace std;
unsigned long long int cifri[18];
int main()
{
    unsigned long long int n,k,minChislo=1;
    cin>>n>>k;
    unsigned long long int cifri[n];
    cifri[0]=1;
    for(int i=1; i<n; i++) cifri[i]=0;
    for(int i=1; i<n; i++)
    {
        minChislo=minChislo*10+cifri[i];
    }
    int buf=minChislo;
    while(minChislo<buf*10)
    {
        if(minChislo<buf*10)
        {
            if(minChislo%k==0) break;
            else minChislo++;
        }
    }
    if(minChislo>=buf*10) cout<<"NO\n";
    else cout<<minChislo<<endl;
    return 0;
}
