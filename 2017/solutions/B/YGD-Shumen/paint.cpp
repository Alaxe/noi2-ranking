#include <iostream>
#include <vector>
using namespace std;
int a[16384][16384],w,h,n,t;
vector <int> p[4];
vector <int> c[2];
void read()
{
    int i,xc,yc,wc,hc;
    cin>>w>>h>>n;
    for(i=0;i<n;i++)
    {
        cin>>xc>>yc>>wc>>hc;
        p[0].push_back(xc);
        p[1].push_back(yc);
        p[2].push_back(wc);
        p[3].push_back(hc);
    }
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>xc>>yc;
        c[0].push_back(xc);
        c[1].push_back(yc);
    }
}
void paint()
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=p[0][i];j<=p[2][i];j++)
        for(k=p[1][i];k<=p[3][i];k++)
        a[j][k]=i+1;    
    }
}
int ccheck(int r,int c)
{
    return a[r][c];
}
int getres(int x)
{
    int i,j,br=0;
    for (i=1;i<w;i++)
        for(j=1;j<h;j++)
        if(a[i][j]==x) br++;
    return br;
}
void solve()
{
    int i,cc;
    for(i=0;i<t;i++)
    {
        cc=a[c[0][i]][c[1][i]];
        cout<<getres(cc)<<endl;
    }
}
int main()
{
    read();
    paint();
    solve();
return 0;
}