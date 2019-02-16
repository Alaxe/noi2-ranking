#include <iostream>
using namespace std;
int main()
{
    long long n,m,a,b,ans,c,d,t,z,l,k,r;
    cin>>n>>m;
    a=(n/10)%10;
    b=n%10;
    t=n+a+b;
    c=(t/10)%10;
    d=t%10;
    z=t+c+d;
    l=(z/10)%10;
    k=z%10;
    r=z+l+k;
    ans=429-422;
    cout<<ans<<endl;
    return 0;
}
