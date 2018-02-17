#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iomanip>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a, b, ans;
    cin>>a>>b;
    double s1, s2;
    s1=(sqrt(4*b+1)+1)/2;
    s1=(int)s1;
    s2=(sqrt(4*a+1)+1)/2;
    if((double)sqrt(4*a+1)==floor((double)sqrt(4*a+1)))
    {
        s2--;
    }
    s2=(int)s2;
    ans=s1-s2;
    cout<<ans<<"\n";
    return 0;
}
