#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int w,h,n,m=1,maxZ[100005];
pair<int,int> in[100005],a[100005];
vector<int> f,v;
long long ans=0;
struct line
{
    int y1,y2,x;
};
vector<line> q;
bool cmp (line o, line c)
{
    return o.x>c.x;
}
int main()
{
    //cin>>w>>h>>n;
    scanf("%d%d%d",&w,&h,&n);
    for (int i=0; i<n; i++)
        //cin>>in[i].first>>in[i].second;
        scanf("%d%d",&in[i].first,&in[i].second);
    a[0]=in[0];
    for (int i=1; i<n-1; i++)
    {
        if (in[i-1].first==in[i].first && in[i].first==in[i+1].first)
            continue;
        if (in[i-1].second==in[i].second && in[i].second==in[i+1].second)
            continue;
        a[m]=in[i];
        m++;
    }
    a[m]=in[n-1];
    m++;
    for (int i=0; i<m; i++)
        f.push_back(a[i].second);
    sort(f.begin(),f.end());
    int sizeF=f.size(), sizeV;
    v.push_back(f[0]);
    for (int i=1; i<sizeF; i++)
        if (f[i]!=f[i-1])
            v.push_back(f[i]);
    sizeV=v.size();
    for (int i=1; i<m; i++)
    {
        if (a[i].first==a[i-1].first)
        {
            line z;
            z.x=a[i].first;
            z.y1=min(a[i].second,a[i-1].second);
            z.y2=max(a[i].second,a[i-1].second);
            q.push_back(z);
        }
    }
    for (int i=0; i<q.size(); i++)
    {
        int b,e;
        b=lower_bound(v.begin(),v.end(),q[i].y1)-v.begin();
        e=lower_bound(v.begin(),v.end(),q[i].y2)-v.begin();
        if (b>e)
            swap(b,e);
        for (int j=b; j<e; j++)
            if (maxZ[j]<q[i].x)
                maxZ[j]=q[i].x;
            else
                break;
        for (int j=e-1; j>=b; j--)
            if (maxZ[j]<q[i].x)
                maxZ[j]=q[i].x;
            else
                break;
    }
    sort(q.begin(),q.end(),cmp);
    for (int i=0; i<sizeV-1; i++)
        ans+=(long long)(w-maxZ[i])*(v[i+1]-v[i]);
    //cout<<ans<<'\n';
    printf("%lld\n",ans);
    return 0;
}

