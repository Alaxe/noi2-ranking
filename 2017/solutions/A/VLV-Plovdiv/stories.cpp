#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int n,k;
long long first,mul,add,mod,ans;

struct L
{
    long long st;
    int ed;


    bool operator < (L x) const
    {
        if (x.st>st) return 1;
        //if (x.ed<ed) return 1;
        return 0;
    }
};

priority_queue<L>pq;

void sol()
{
    L F;
    F.st=first;
    F.ed=k;
    pq.push(F);
    long long pre;
    pre=first;
    long long ne;
    int i=1;
    while(1)
    {
        while (pq.top().ed<i) pq.pop();
        ans=ans+pq.top().st;
        //cout<<"bla: "<<pq.top().st<<endl;

        ne=(pre*mul%mod+add)%mod;
        F.st=ne;
        F.ed=k+i;
        pq.push(F);
        i++;
        pre=ne;
        //cout<<ans<<endl;
        if (i>n) break;
    }
}

int main ()
{
    cin>>n>>k;
    cin>>first>>mul>>add>>mod;
    sol();
    cout<<ans<<endl;
    return 0;
}
