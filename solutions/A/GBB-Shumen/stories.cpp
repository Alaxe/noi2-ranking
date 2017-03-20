#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct kkk
{
    long long v, idx;
    bool operator < (const kkk &p) const
    {
        return (v<p.v);
    }
};
unsigned long long ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, i;
    long long first, mul, add, mod;
    priority_queue<kkk>pq;
    kkk cur, c;
    cin>>n>>k;
    cin>>first>>mul>>add>>mod;
    ans=first;
    cur.v=first;
    cur.idx=1;
    pq.push(cur);
    for(i=2;i<=n;i++)
    {
        cur.v*=mul;
        cur.v+=add;
        cur.v%=mod;
        cur.idx=i;
        pq.push(cur);
        for(;1;)
        {
            c=pq.top();
            if(i-c.idx>=k) pq.pop();
            else break;
        }
        ans+=c.v;
    }
    cout<<ans<<"\n";
    return 0;
}
