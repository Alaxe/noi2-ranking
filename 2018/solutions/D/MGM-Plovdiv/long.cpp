#include <bits/stdc++.h>
using namespace std;
long long MAXN=(int)1e9;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned long long x, n, k, cnt, xcpy;
    cin>>n>>k;
    for(int i=2; i<=MAXN; i++)
    {
        x=k*i;
        xcpy=x;
        cnt=0;
        while(xcpy>0)
        {
            cnt++;
            xcpy/=10;
        }
        if(cnt==n) {cout<<x<<endl; return 0;}
    }
    return 0;
}
