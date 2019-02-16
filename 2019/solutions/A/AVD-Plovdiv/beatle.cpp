#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
struct node
{
    int l,r,ans,lazy;
};
pair<pair<int,int>,int>p[MAXN];
int tests,x[MAXN];
struct seg_tree
{
    node tree[4*MAXN];
    void build_tree(int l,int r,int idx)
    {
        if(l==r)
        {
            tree[idx].l=tree[idx].r=l;
            tree[idx].ans=0;
            tree[idx].lazy=0;
            return;
        }
        int mid=(l+r)>>1;
        build_tree(l,mid,idx<<1);
        build_tree(mid+1,r,idx<<1|1);
        tree[idx].l=l;
        tree[idx].r=r;
        tree[idx].ans=0;
        tree[idx].lazy=0;
    }
    int query(int l,int r,int idx,int qidx)
    {
        if(l==r && l==qidx)
        {
            if(tree[idx].lazy!=0)
            {
                tree[idx].ans=tree[idx].lazy;
                tree[idx].lazy=0;
                return tree[idx].ans;
            }
            else
                return tree[idx].ans;
        }
        int mid=(l+r)>>1;
        if(tree[idx].lazy!=0)
        {
            tree[idx<<1].lazy=tree[idx].lazy;
            tree[idx<<1|1].lazy=tree[idx].lazy;
            tree[idx].lazy=0;
        }
        if(qidx>mid)
            return query(mid+1,r,idx<<1|1,qidx);
        else
            return query(l,mid,idx<<1,qidx);
    }
    void update(int l,int r,int ql,int qr,int idx,int val)
    {
        if(l>qr || r<ql)
            return;
        if(l>=ql && r<=qr)
        {
            tree[idx].ans=val;
            tree[idx].lazy=val;
            return;
        }
        int mid=(l+r)>>1;
        update(l,mid,ql,qr,idx<<1,val);
        update(mid+1,r,ql,qr,idx<<1|1,val);
    }
};
bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b)
{
    if(a.first.second!=b.first.second)
        return(a.first.second<b.first.second);
    else
    {
        return a.first.first<b.first.first;
    }
}
seg_tree t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    t.build_tree(1,MAXN,1);
    for(int i=0;i<n;i++)
    {
        cin>>p[i].first.first;
        cin>>p[i].first.second;
        cin>>p[i].second;
    }
    cin>>tests;
    for(int i=0;i<tests;i++)
        cin>>x[i];
    sort(p,p+n,cmp);
    for(int i=0;i<n;i++)
    {
        int l,r;
        l=p[i].first.first+1;
        r=l+p[i].second-1;

        int tobe=min(t.query(1,MAXN,1,l-1),t.query(1,MAXN,1,r+1));
        t.update(1,MAXN,l,r,1,tobe+1);
    }
    for(int i=0;i<tests-1;i++)
    {
        cout<<t.query(1,MAXN,1,x[i]+1)<<" ";
    }
    cout<<t.query(1,MAXN,1,x[tests-1]+1)<<endl;
    return 0;
}
/*
13
1 4 2
9 5 2
8 1 5
2 2 2
6 2 2
2 6 3
1 3 1
4 3 2
9 3 3
5 4 5
4 5 2
7 5 1
8 6 2
5
2 5 7 8 11
*/
