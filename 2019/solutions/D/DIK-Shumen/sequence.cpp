#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    long long n,k;
    cin>>n>>k;
    long long ans=(n-1)*(n-1);
    ans=ans+n;
    k--;
    if (k!=0)ans=ans+(n-1);
    long long red=n+1;
    while(k>2)
    {
        ans=ans+red*2-1;
        k=k-2;
        red++;
    }
    if (k==1)ans=ans+n;
    else if (k==2)ans=ans+(red*2-1)-(n-1);
    cout<<ans<<endl;
    return 0;
}
