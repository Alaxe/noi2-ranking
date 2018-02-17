#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long i,j,n,sum=1,rez=0;
    cin>>n;
    for (i=1;i<=n;i++)
    {
        sum*=i;
    }
    while (sum>0)
    {
        rez+=(sum%10);
        sum/=10;
    }
    cout<<rez<<endl;
}
