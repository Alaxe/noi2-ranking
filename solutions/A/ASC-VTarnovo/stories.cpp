#include <iostream>
#include <queue>
using namespace std;

struct segment
{
    long long from;
    long long to;
    long long val;
};

segment x[20000000];
long long a,mul,add,MOD,k,n,upd;
queue <long long> remq;

void build(long long i,long long from,long long to)
{
    x[i].from=from;
    x[i].to=to;
    if(from==to)
    {
        x[i].val=0;
        remq.push(i);
        return ;
    }
    build(i*2,from,(from+to)/2);
    build(i*2+1,(from+to)/2+1,to);
    x[i].val=x[i*2].val+x[i*2+1].val;
}

void update(long long i)
{
    ///cout<<i<<endl;
    x[i].val=max(x[i*2].val,x[i*2+1].val);
    if(i!=1)
        update(i/2);
}

int main()
{
    long long ans=0;
    cin>>k>>n;
    cin>>a>>mul>>add>>MOD;
    build(1,0,n-1);
    for(long long i=0;i<k;i++)
    {
        upd=remq.front();
        ///cout<<upd<<endl;
        remq.pop();
        x[upd].val=a;
        update(upd/2);
        a=(a*mul+add)%MOD;
        remq.push(upd);
        ans+=x[1].val;
    }
    cout<<ans<<endl;
}
/*
133742 666
20 3 17 1000000007

*/
