#include <iostream>
#include <cstdint>
#include <algorithm>
using namespace std;

#define NMAX 100032
#define XMAX 100032 //ho ho ho

int lazy[4*NMAX*4]; //da ima
                    //ot google chrome sum sa uchil

inline void lazy_pull_down (int cur)
{
    lazy[(cur<<1)  ]=lazy[cur];
    lazy[(cur<<1)+1]=lazy[cur];
    lazy[cur]=0;
}

int lazy_get_idx (int cur, int l, int r, int idx)
{
    //cout<<lazy[cur]<<' '<<cur<<' '<<l<<' '<<r<<endl;

    if(l==r)
    {
        if(l==idx)
            return lazy[cur];
        else
            return INT32_MAX;
    }

    int mid=(l+r)>>1;

    //cout<<lazy[cur]<<endl;

    if(lazy[cur]!=0)
        lazy_pull_down(cur);

    if(idx<=mid)
        return lazy_get_idx((cur<<1), l, mid, idx);
    else
        return lazy_get_idx((cur<<1)+1, mid+1, r, idx);
}

void lazy_update (int cur, int l, int r, int ul, int ur, int uv)
{

    //cout<<cur<<' '<<l<<' '<<r<<' '<<ul<<' '<<ur<<' '<<uv<<endl;
    //system("pause");

    if(ul<=l&&r<=ur)
    {
        //cout<<"Updated:"<<cur<<' '<<uv<<' '<<l<<' '<<r<<endl;
        lazy[cur]=uv;
        return;
    }

    int mid=(l+r)>>1;

    //cout<<mid<<endl;
    //system("pause");

    if(lazy[cur]!=0)
        lazy_pull_down(cur);

    //if((l<=ul&&ul<=mid)||(l<=ur&&ur<=mid)||(ul<=l&&mid<=ur))
    if(!((mid<ul)||(ur<l)))
        lazy_update((cur<<1), l, mid, ul, ur, uv);
    //if((mid+1<=ul&&ul<=r)||(mid+1<=ur&&ur<=r)||(ul<=mid+1&&r<=ur))
    if(!((r<ul)||(ur<mid+1)))
        lazy_update((cur<<1)+1, mid+1, r, ul, ur, uv);
}

int n;
struct daska
{
    int x, y, d;
};

daska ds[NMAX];

bool cmp_daska_y(const daska &a, const daska &b)
{
    if(a.y==b.y)
    {
        if(a.x==b.x)
        {
            return a.d<b.d;
        }
        return a.x<b.x;
    }
    return a.y<b.y;
}

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;

    for(int i=0; i<n; i++)
    {
        //cout<<ds[i].x<<' '<<ds[i].y<<' '<<ds.d<<endl;
        cin>>ds[i].x>>ds[i].y>>ds[i].d;
    }

    sort(ds, ds+n, cmp_daska_y);

    for(int i=0; i<n; i++)
    {
        int tmp_a, tmp_b;
        tmp_a=lazy_get_idx(1, 0, XMAX, ds[i].x-1);
        tmp_b=lazy_get_idx(1, 0, XMAX, ds[i].x+ds[i].d);
        tmp_a=min(tmp_a, tmp_b);
        //cout<<tmp_a<<endl;
        //system("pause");
        lazy_update(1, 0, XMAX, ds[i].x, ds[i].x+ds[i].d-1, tmp_a+1);
    }
}

void show (int n)
{
    for(int i=0; i<=n; i++)
    {
        cout<<lazy_get_idx(1, 0, XMAX, i)<<' ';
    }
    cout<<endl;
}

void solve()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int x;
        cin>>x;
        cout<<lazy_get_idx(1, 0, XMAX, x)<<' ';
    }
    cout<<'\n';
}

int main()
{
    init();

    //lazy_update(1, 0, 13, 2, 4, 1);
    //lazy_update(1, 0, 13, 6, 8, 1);


    //cout<<'a'<<endl;

    //cout<<lazy_get_idx(1, 0, 13, 6);

    //show(13);

    solve();


    return 0;
}
