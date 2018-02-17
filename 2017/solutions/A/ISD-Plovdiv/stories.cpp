#include<bits/stdc++.h>
#define MAXN 10000042
using namespace std;
#define int long long
int segtree[3*MAXN];
int a[MAXN];
int mx[MAXN];
int k,n;
int FIRST,MUL,ADD,MOD;
int aaa=0;
void build(int l, int r, int idx)
{
    if(l==r)
    {
        segtree[idx]=a[l];
        return;
    }
    int mid=l+(r-l)/2;
    build(l,mid,idx*2);
    build(mid+1,r,idx*2+1);
    segtree[idx]=max(segtree[idx*2],segtree[idx*2+1]);
}
void rmq(int l,int r,int ql, int qr, int idx)
{
    if(l>=ql && r<=qr){
            aaa=max(aaa,segtree[idx]);return;}
    if(l==r)return;
    if(l>qr || r<ql)return;
    int mid=l+(r-l)/2;
    rmq(l,mid,ql,qr,idx*2);
    rmq(mid+1,r,ql,qr,idx*2+1);
}
#undef int
int main()
{
#define int long long
    cin>>n>>k;
    cin>>FIRST>>MUL>>ADD>>MOD;
    a[0]=FIRST;
    for(int i=1;i<n;i++)
    {
        a[i]=(a[i-1]*MUL+ADD)%MOD;
    }
    build(0,n,1);
    //for(int i=0;i<3*n;i++)cout<<segtree[i]<<" "<<endl;
    int ans=0;
    int crrmx=0,d=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>=crrmx)
        {
            crrmx=a[i];
            ans+=a[i];
            d=1;
        }
        else
        {
            d++;
            if(d<=k)ans+=crrmx;
            else
            {
                aaa=0;
                rmq(0,n,i-k+1,i,1);
                crrmx=aaa;
                ans+=aaa;
            }

        }
        //cout<<crrmx<<endl;
        /* aaa=0;
        rmq(0,n,i-k+1,i,1);
        crrmx=aaa;
        ans+=aaa;*/
    }
    cout<<ans<<endl;
    return 0;
}

