#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int n,tek,t,bam;
struct masiv
{
    int x,y,d;
};
masiv arr[MAXN];
struct Tree
{
    int l,r,x,lazy;
};
Tree tree[4*MAXN];
bool cmp(masiv a,masiv b)
{
    if(a.y>b.y)return 1;
    return 0;
}
long long query(int l,int r,int ind,int now)
{
    if(l==r)
    {
        if(tree[ind].lazy)
        {
            tree[ind].x=tree[ind].lazy;
            tree[ind].lazy=0;
        }
        return tree[ind].x;
    }
    if(tree[ind].lazy)
    {
        tree[ind<<1].lazy=tree[ind].lazy;
        tree[ind<<1|1].lazy=tree[ind].lazy;
        tree[ind].lazy=0;
    }
    int mid=(l+r)>>1;
    if(now>mid)
        return query(mid+1,r,ind<<1|1,now);
    else
        return query(l,mid,ind<<1,now);
}
void update(int l,int r,int ind,int left,int right,int st)
{
    if(r<left || l>right)return;
    if(left<=l && r<=right)
    {
        tree[ind].lazy=st;
        return;
    }
    int mid=(l+r)/2;
    update(l,mid,ind*2,left,right,st);
    update(mid+1,r,ind*2+1,left,right,st);
    //tree[ind].x=min(tree[ind*2].x,tree[ind*2+1].x);
}
void build(int l,int r,long long ind)
{
    //if(l>120000)cout<<l<<" "<<r<<" "<<ind<<endl;
    if(l<r)
    {
        build(l,(l+r)/2,ind*2);
        build((l+r)/2+1,r,ind*2+1);
        tree[ind].l=l;
        tree[ind].r=r;
    }
    else
    if(l==r)
    {
        tree[ind].l=l;
        tree[ind].r=r;
    }
    else return;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i].x>>arr[i].y>>arr[i].d;
    sort(arr,arr+n,cmp);
    build(1,(1<<18),1);
    for(int i=n-1;i>=0;i--)
    {
        tek=min(query(1,(1<<18),1,arr[i].x),query(1,(1<<18),1,arr[i].x+arr[i].d+1));
        //cout<<arr[i].y<<" "<<arr[i].x<<" "<<arr[i].d+arr[i].x<<" "<<tek<<endl;
        update(1,(1<<18),1,arr[i].x+1,arr[i].x+arr[i].d,tek+1);
    }
    cin>>t;
    for(int i=0;i<t-1;i++)
    {
        cin>>bam;
        cout<<query(1,(1<<18),1,bam+1)<<" ";
    }
    cin>>bam;
    cout<<query(1,(1<<18),1,bam+1)<<endl;
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
