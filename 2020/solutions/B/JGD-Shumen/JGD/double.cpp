#include<bits/stdc++.h>
using namespace std;
const int MAXN = 256;
int n;
bool f=false;
int w1,w2,w,ww;
int cnt;
int cnt2;
int cnts;
int zed;
int r[MAXN];
int used[MAXN];
int a[MAXN][MAXN];
int c[MAXN];
int d=1;
int b[MAXN][MAXN];
void read()
{
    cin>>n;
    cin>>w1>>w2;
    for(int i=1;i<=n;i++)
        cin>>r[i];
        sort(r,r+n+1);
        if(w1>w2){w=w1;ww=w2;}
        else {w=w2;ww=w1;}
}
void fillk()
{
    for(int i=1;i<=n;i++)
    {
         a[i][1]=r[i];
        for(int j=2;j<=n;j++)
        {
            a[i][j]+=a[i][1];
            for(int p=i-1;p>=1;p--)
            if(a[i][j]+a[i-1][1]>a[p][j]&&a[i][j]+a[p][1]<=w){a[i][j]+=a[i-1][1];c[d]=a[i-1][1];d++;break;}
            else if(a[i-1][j]>a[i][j]&&a[i-1][j]+a[i][j]<=w){a[i][j]+=a[i-1][j];c[d]=a[i-1][j];d++;}
            else a[i][j]=a[i][j-1];
            if(a[i][j]>cnt&&a[i][j]<=w)cnt=a[i][j];
        }
    }
    cnts=cnt;
    zed=1;
    for(int i=n;i>=0;i--)
    {
        if(cnt-r[i]>0)
        {
            for(int j=i;j>=0;j--)
            {
                if(cnt-r[j]>=0)c[zed]=r[j];
                cnt-=r[j];
                zed++;
                if(cnt<0){memset(c,0,sizeof(c));break;}
                if(cnt==0){f==true;break;}
            }
        }
        if(f==true)break;
        zed=1;
        cnt=cnts;
    }
    for(int i=1;i<=n;i++)
    {
        if(r[i]==c[i])r[i]=0;
    }
        for(int i=1;i<=n;i++)
    {
         b[i][1]=r[i];
        for(int j=2;j<=n;j++)
        {
            b[i][j]+=b[i][1];
            for(int p=i-1;p>=1;p--)
            if(b[i][j]+b[p][1]>b[i-1][j]&&b[i][j]+b[p][1]<=ww){b[i][j]+=b[p][1];c[d]=b[i-1][1];d++;break;}
            else if(b[i-1][j]>b[i][j]&&b[i-1][j]+b[i][j]<=ww){a[i][j]+=b[i-1][j];c[d]=b[i-1][j];d++;}
            else b[i][j]=b[i][j-1];
            if(b[i][j]>cnt2&&b[i][j]<=ww)cnt2=b[i][j];
        }
    }
    cout<<cnts+cnt2<<endl;
    /*
    for(int i=1;i<=d;i++)
        cout<<c[i]<<endl;
    cout<<cnt<<endl;
    cout<<cnt2<<endl;
    cout<<cnt+cnt2<<endl;*/
}
int main()
{
	read();
	fillk();
	return 0;
}
