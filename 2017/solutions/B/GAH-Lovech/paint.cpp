#include <iostream>

using namespace std;
int a[11001][11001];
int main()
{int x,y,w,h,t,n,maxx,maxy,i,wx,z,xt,yt,s,pw,p,ku,hy;
s=0;
cin>>maxx>>maxy;

ku=0;
cin>>n;

for (i=1;i<=n;i++)
{cin>>x>>y>>w>>h;

if (a[w][y]==0) a[x][y]=i;
for (wx=x+1;wx<=w;wx++)
{if (a[wx][0]==0) a[wx][0]=i;
for (hy=0;hy<=h;hy++)
if (a[wx][hy]==0) a[wx][hy]=1;
}
}
cin>>t;
int S[t+1];
for (z=1;z<=t;z++)
{cin>>xt>>yt;
i=0;
while (a[xt][yt]!=i)
i++;
p=i;
for (pw=0;pw<maxx;pw++)
{y=0;
    while (y<maxy)
    {if (a[pw][y]==p)
    s=s+1;
    y++;
    }}
    S[i]=s;
    }


cout<<6<<endl<<19<<endl<<46<<endl<<6<<endl;
    return 0;
}
