#include<bits/stdc++.h>
#include<cstdio>
#define MAXN (1<<17)
using namespace std;
long long n,a,b;
set<long long>x;
long long ans;
map<long long,long long>mp;
long long N;
pair<long long,long long>p[100023];
struct bla
{
    long long a,b,l;
    bla(long long _a,long long _b,long long _l)
    {
        a=_a;
        b=_b;
        l=_l;
    }
};
vector<bla>v;
vector<long long>mama;
bool cmp(bla a,bla b)
{
    if(a.l!=b.l)
        return a.l<b.l;
    else
    {
        if(a.a!=b.a)
            return a.a<b.a;
        else
            return a.b<b.b;
    }
}
struct nd
{
    long long l,r,maxx,lazy;
};
struct seg3
{
    nd tree[5*MAXN];
    void build_tree(long long l,long long r,long long idx)
    {
        if(l==r)
        {
            tree[idx].l=tree[idx].r=l;
            tree[idx].maxx=0;
            tree[idx].lazy=0;
            return;
        }
        long long mid=(l+r)>>1;
        build_tree(l,mid,idx<<1);
        build_tree(mid+1,r,idx<<1|1);
        tree[idx].l=l;
        tree[idx].r=r;
        tree[idx].maxx=0;
        tree[idx].lazy=0;
    }
    void update(long long l,long long r,long long idx,long long ql,long long qr,long long lazy)
    {
        if(ql>r || qr<l)
            return;
        if(ql<=l && qr>=r)
        {
            tree[idx].lazy=lazy;
            return;
        }
        long long mid=(l+r)>>1;
        update(l,mid,idx<<1,ql,qr,lazy);
        update(mid+1,r,idx<<1|1,ql,qr,lazy);
    }
    long long get_a(long long l,long long r,long long idx,long long x)
    {
        long long mid=(l+r)>>1;
        if(l==r)
        {
            tree[idx].maxx=max(tree[idx].maxx,tree[idx].lazy);
            tree[idx].lazy=0;
            return tree[idx].maxx;
        }
        tree[idx<<1].lazy=max(tree[idx].lazy,tree[idx<<1].lazy);
        tree[idx<<1|1].lazy=max(tree[idx].lazy,tree[idx<<1|1].lazy);
        tree[idx].lazy=0;
        if(x<=mid)
            return get_a(l,mid,idx<<1,x);
        else
            return get_a(mid+1,r,idx<<1|1,x);
    }
};
seg3 t;
int main()
{
    scanf("%lld%lld%lld",&a,&b,&n);
    for(long long i=0;i<n;i++)
    {
        scanf("%lld%lld",&p[i].first,&p[i].second);
        x.insert(p[i].second);
    }
    for(long long i=0;i<n-1;i++)
    {
        if(p[i].first==p[i+1].first)
        {
            long long QQ=p[i].second,QQQ=p[i+1].second;
            if(QQ>QQQ)swap(QQ,QQQ);
            v.push_back(bla(QQ,QQQ,p[i].first));
        }
    }
    N=x.size();
    long long d=1;
    for(set<long long>::iterator it=x.begin();it!=x.end();it++)
    {
        mp[*it]=d;
        d++;
        mama.push_back(*it);
    }
    sort(v.begin(),v.end(),cmp);
    for(long long i=0;i<v.size();i++)
        v[i].a=mp[v[i].a],v[i].b=mp[v[i].b];
    t.build_tree(1,N,1);
    for(long long i=0;i<v.size();i++)
    {
        t.update(1,N,1,v[i].a+1,v[i].b,v[i].l);
    }
    ans=a*b;
    for(long long i=2;i<=N;i++)
        ans-=(mama[i-1]-mama[i-2])*t.get_a(1,N,1,i);
    printf("%lld\n",ans);
    return 0;
}
/*
15 10
16
6 0
6 2
11 2
11 6
8 6
8 4
9 4
9 5
10 5
10 3
6 3
6 7
12 7
12 8
9 8
9 10
*/
