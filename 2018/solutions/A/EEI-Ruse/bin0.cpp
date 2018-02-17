#include<iostream>
#include<vector>
using namespace std;
const int MAX_Z=64;
long long c[MAX_Z][MAX_Z];
long long ans=0;
int z;
long long s,t;
void getLevels()
{
    c[0][0]=1;
    for (int i=1; i<MAX_Z; ++i)
    {
        c[0][i]=0;
    }
    for (int i=1; i<MAX_Z; ++i)
    {
        c[i][0]=1;
        for (int j=1; j<MAX_Z; ++j)
        {
            c[i][j]=c[i-1][j]+c[i-1][j-1];
        }
    }
}
long long upTo(long long a, int dig)
{
    if (a==0) return 0;
    if (a==1 && dig==0) return 1;
    else if (a==1) return 0;
    if (dig<0) return 0;
    long long ans=0;
    long long k=2;
    int cl=0;
    while (k<=min(a+1,a*2-1))
    {
        ans+=c[cl][dig];
        ++cl;
        k=k<<1;
    }
    k=k>>1;
    a-=k-1;
    while (a>0)
    {
        while (k>a)
        {
            k=k>>1;
            --cl;
            --dig;
        }
        if (dig<0) return ans;
        ans+=c[cl][dig];
        a-=k;
        ++dig;
    }
    return ans;
}
void solve()
{
    getLevels();
    ans=upTo(t,z)-upTo(s-1,z);
}
void input()
{
    cin>>s>>t>>z;
}
void output()
{
    cout<<ans<<endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    input();
    solve();
    output();
    return 0;
}
