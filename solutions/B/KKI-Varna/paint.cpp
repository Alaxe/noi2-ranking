#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
    int x,y,x1,y1,s;
};
node m[11005];
int cmp(node a, node b)
{
    if(a.s!=b.s)return a.s<b.s;
    if(a.x!=b.x)return a.x<b.x;
    return a.y<b.y;
}
bool check(int i, int j)
{
    if(m[i].x>m[j].x&&m[i].x1<m[j].x1&&m[i].y>m[j].y&&m[i].y1<m[j].y1)return 1;
    return 0;

}
bool checky(int b,int a,int i)
{
    if(a>m[i].x&&a<m[i].x1&&b>m[i].y&&b<m[i].y1)return 1;
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int o1,o2;
    cin>>o1>>o2;
    m[0].x=0;
    m[0].y=0;
    m[0].x1=o1;
    m[0].y1=o2;
    int n,x,y,a,b;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>y>>x>>a>>b;
        m[i].x=x;
        m[i].y=y;
        m[i].x1=x+b;
        m[i].y1=y+a;
        m[i].s=a*b;
    }
    sort(m+1,m+n+1,cmp);
    m[0].s=o1*o2;
    for(int i=1; i<=n; i++)
    {
        m[0].s-=m[i].s;
        for(int j=i+1; j<=n; j++)
        {
            if(check(i,j))
            {
                m[j].s-=m[i].s;
            }
        }
    }
    int p;
    cin>>p;
    bool r=0;
    for(int i=0; i<p; i++)
    {
        cin>>a>>b;
        r=0;
        for(int j=1; j<=n; j++)
        {
            if(checky(a,b,j))
            {
                cout<<m[j].s<<endl;
                r=1;
                break;
            }
        }
        if(r==0)cout<<m[0].s<<endl;
    }
}
/**
11 7
3
2 1 5 5
8 2 2 3
3 2 3 2
4
4 3
3 5
10 1
9 3

3
2 1 5 5
3 2 3 3
3 4 1 1



*/
