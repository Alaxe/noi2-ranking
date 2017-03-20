#include<cstdio>
using namespace std;
int xA,yA,n,m;
int a[11005][11005],s[11005];
int main()
{
    //cin>>xA>>yA>>n;
    scanf("%d%d%d",&xA,&yA,&n);
    s[0]=xA*yA;
    for (int i=0; i<n; i++)
    {
        int x,y,w,h;
        //cin>>x>>y>>w>>h;
        scanf("%d%d%d%d",&x,&y,&w,&h);
        s[i+1]=w*h;
        s[a[x][y]]-=w*h;
        for (int k=y; k<y+h; k++)
            for (int j=x; j<x+w; j++)
                a[j][k]=i+1;
    }
    //cin>>m;
    scanf("%d",&m);
    for (int i=0; i<m; i++)
    {
        int x,y;
        //cin>>x>>y;
        scanf("%d%d",&x,&y);
        //cout<<s[a[x][y]]<<'\n';
        printf("%d\n",s[a[x][y]]);
    }
}
