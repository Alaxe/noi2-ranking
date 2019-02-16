#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct line
{
    int x,y,d;
    int num;
} l[100005];
int n,lft=(1<<31)-1,rght=0;
struct tree
{
    int lazy;
} t[262144];
bool cmp (line a, line b)
{
    return a.y<b.y;
}
int ans[100005];
int findNext (int pos, int ll, int rr, int num)
{
    if (!(ll<=pos && pos<=rr))
        return 0;
    if (ll==rr)
        return t[num].lazy;
    t[num*2].lazy=max(t[num*2].lazy,t[num].lazy);
    t[num*2+1].lazy=max(t[num*2+1].lazy,t[num].lazy);
    t[num].lazy=0;
    int mid=(ll+rr)/2;
    return max(findNext(pos,ll,mid,num*2),findNext(pos,mid+1,rr,num*2+1));
}
void update (int a, int b, int ll, int rr, int num, int z)
{
    if (rr<a || b<ll)
        return;
    if (a<=ll && rr<=b)
    {
        t[num].lazy=z;
        return;
    }
    int mid=(ll+rr)/2;
    update(a,b,ll,mid,num*2,z);
    update(a,b,mid+1,rr,num*2+1,z);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for (int i=0; i<n; i++)
    {
        int x,y,d;
        cin>>x>>y>>d;
        lft=min(lft,x);
        rght=max(rght,x+d);
        l[i].x=x;
        l[i].y=y;
        l[i].d=d;
        l[i].num=i+1;
    }

    stable_sort(l,l+n,cmp);

    for (int i=0; i<n; i++)
    {
        int ll=findNext(l[i].x-1,1,131072,1);
        int rr=findNext(l[i].x+l[i].d,1,131072,1);
        ans[i+1]=min(ans[ll],ans[rr])+1;
        update(l[i].x,l[i].x+l[i].d-1,1,131072,1,i+1); ///
    }

    int t;
    cin>>t;
    for (int i=0; i<t; i++)
    {
        int z;
        cin>>z;
        int p=findNext(z,1,131072,1);
        if (i==0)
            cout<<ans[p];
        else
            cout<<' '<<ans[p];
    }
    cout<<'\n';

    return 0;
}
