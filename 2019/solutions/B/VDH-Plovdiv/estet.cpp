#include <iostream>
using namespace std;
int n, a[100020], tr[100020], tr2[100020], ans[100020], ans1[100020], i;
void update(int l, int r, int idx, int d)
{
    if (l==r) tr[idx]=ans[i];
    if (l<r)
    {
        int mid=(l+r)/2;
        if (mid>=d)
            update(l, mid, idx*2+1, d);
        else
            update(mid+1, r, idx*2+2, d);
        tr[idx]=max(tr[idx*2+1], tr[idx*2+2]);
    }
}
int query(int l, int r, int ql, int qr, int idx)
{
    if (l>r || l>qr || r<ql || qr<ql) return 0;
    if (l==r) return tr[idx];
    int mid=(l+r)/2;
    int br1=query(l, mid, ql, qr, idx*2+1);
    int br2=query(mid+1, r, ql, qr, idx*2+2);
    return max(br1, br2);
}
void update1(int l, int r, int idx, int d)
{
    if (l==r) tr2[idx]=ans1[i];
    if (l<r)
    {
        int mid=(l+r)/2;
        if (mid>=d)
            update1(l, mid, idx*2+1, d);
        else
            update1(mid+1, r, idx*2+2, d);
        tr2[idx]=max(tr2[idx*2+1], tr2[idx*2+2]);
    }
}
int query1(int l, int r, int ql, int qr, int idx)
{
    if (l>r || l>qr || r<ql || ql>qr) return 0;
    if (l==r) return tr2[idx];
    int mid=(l+r)/2;
    int br1=query1(l, mid, ql, qr, idx*2+1);
    int br2=query1(mid+1, r, ql, qr, idx*2+2);
    return max(br1, br2);
}
int main()
{
    cin>>n;
    int maxx=0;
    for (int i=0; i<n; i++){
        cin>>a[i];
        maxx=max(a[i], maxx);}
    for (i=0; i<n; i++)
    {
        ans[i]=query(1, maxx, 1, a[i]-1, 0)+1;
        update(1, maxx, 0, a[i]);
    }
    for (i=n-1; i>=0; i--)
    {
        ans1[i]=query1(1, maxx, 1, a[i]-1, 0)+1;
        update1(1, maxx, 0, a[i]);
    }
    int max1=0, max2=0, max3=0;
    for (int i=0; i<n; i++)
    {
        max1=max(max1, ans[i]);
        max2=max(max2, ans1[i]);
        max3=max(max3, ans[i]+ans1[i]-1);
    }
    cout<<max(max1, max(max2, max3));
}
