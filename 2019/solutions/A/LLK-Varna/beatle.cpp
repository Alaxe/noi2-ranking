#include<iostream>
#include<algorithm>
#define MAX 100001
using namespace std;
struct ots
{
    int x,y,d;
};

bool cmp(ots a,ots b)
{
    if(a.y==b.y)
        return (a.x<b.x);
    return (a.y<b.y);
}

int n;
ots p[MAX];
int level[MAX];
int ans[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    cin>>n;
    for(int a=0; a<n; a++)
        cin>>p[a].x>>p[a].y>>p[a].d;
    p[n].x=0;
    p[n].y=0;
    p[n].d=MAX;

    sort(p,p+n+1,cmp);

    for(int a=1; a<=n; a++)
        level[a]=MAX;
    bool left,right;
    for(int a=0; a<=n; a++)
    {
        left=false;
        right=false;
        for(int b=a-1; b>=0; b--)
        {
            if(left==true && right==true)
                break;
            if(p[a].x>p[b].x && p[a].x<=p[b].x+p[b].d && left==false)
            {
                level[a]=min(level[a],level[b]+1);
                left=true;
            }
            if(p[a].x+p[a].d>=p[b].x && p[a].x+p[a].d<p[b].x+p[b].d && right==false)
            {
                level[a]=min(level[a],level[b]+1);
                right=true;
            }
        }
    }

    for(int a=n; a>=1; a--)
    {
        for(int b=p[a].x; b<p[a].x+p[a].d; b++)
            if(ans[b]==0)ans[b]=level[a];
    }
    int t,q;
    cin>>t;
    for(int a=0; a<t-1; a++)
    {
        cin>>q;
        cout<<ans[q]<<" ";
    }
    cin>>q;
    cout<<ans[q]<<endl;
    return 0;
}

