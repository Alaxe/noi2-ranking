#include <cstdio>
#include <cstring>

using namespace std;

const int nMax=1024;
const long long MOD=123456789012345LL;

struct MyStruct
{
    long long x[nMax];
};

int n, diff;
long long ans=0;

int a[nMax];
MyStruct v[nMax];

int main ()
{
    //freopen("i31.txt", "r", stdin);
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &a[i]);
        memset(v[i].x, 0, sizeof v[i].x);
    }
    for(int i=1; i<n; ++i)
    {
        for(int j=i-1; j>=0; --j)
        {
            if(a[i]<=a[j])
            {
                continue;
            }
            diff=a[i]-a[j];
            if(v[j].x[diff]==0)
            {
                v[i].x[diff]=(v[i].x[diff]+1LL)%MOD;
            }
            else
            {
               v[i].x[diff]=(v[i].x[diff]+v[j].x[diff]+1LL)%MOD;
            }
        }
    }
    for(int i=0; i<nMax; ++i)
    {
        for(int j=0; j<nMax; ++j)
        {
            ans=(ans+v[i].x[j])%MOD;
        }
    }
    printf("%lld\n", ans);
    return 0;
}