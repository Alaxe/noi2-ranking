#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
struct zaq
{
    long long st;
    int t;
    zaq(){}
    zaq(long long _st, int _t)
    {
        st = _st;
        t = _t;
    }
    bool operator < (const zaq &p)   const
    {
        return (st < p.st);
    }
};
int N, K;
long long ans;
priority_queue <zaq> Q;
int main()
{
    long long fir, mul, add, mod;
    scanf("%d %d", &N, &K);
    scanf("%lld %lld %lld %lld", &fir, &mul, &add, &mod);
    Q.push(zaq(fir, 1));
    ans += fir;
    long long sq = fir;
    for(int i = 2; i <= N; ++ i)
    {
        long long curr = (sq * mul + add) % mod;
        Q.push(zaq(curr, i));
        while(1)
        {
            zaq dab = Q.top();
            if(dab.t >= i - K + 1)
            {
                ans += dab.st;
                break;
            }
            else   Q.pop();
        }
        sq = curr;
    }
    printf("%lld\n", ans);
    return 0;
}