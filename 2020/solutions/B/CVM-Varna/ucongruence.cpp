#include<bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
using namespace std;
int m[1000001],n,u,k;
bool cmp(pii a,pii b)
{
    return a.first<b.first;
}
void norm()
{
    vector<pii> v;
    for(int i=0;i<n;i++) v.pb({m[i],i});
    sort(v.begin(),v.end(),cmp);
    k=1;
    m[v[0].second]=k;
    for(int i=1;i<n;i++)
    {
        if(v[i].first!=v[i-1].first) k++;
        m[v[i].second]=k;
    }
}
int br=0;
void rec(int x=0,int y=1)
{
    if(x==k){br++; return ;}
    for(int i=y;i<=u-k+x+1;i++) rec(x+1,i+1);
}
bool ff=0;
int br1=0;
int rel[64];
void cnt_rec(int x=0,int y=1)
{
    if(ff) return ;
    if(x==k)
    {
        br1++;
        if(br1==((br+1)>>1)) ff=1;
        return ;
    }
    for(int i=y;i<=u-k+x+1;i++)
    {
        rel[x+1]=i;
        cnt_rec(x+1,i+1);
        if(ff) return ;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>u;
    for(int i=0;i<n;i++) cin>>m[i];
    norm();
    rec();
    cnt_rec();
    m[0]=rel[m[0]];
    cout<<m[0];
    for(int i=1;i<n;i++)
    {
        m[i]=rel[m[i]];
        cout<<" "<<m[i];
    }cout<<endl;
    return 0;
}
/**

4 26
4 6 6 4

*/
