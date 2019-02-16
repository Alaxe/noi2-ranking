#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n, xmax=-1, ymax=-1, b[15005][15005];bool a[15005][15005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y,d;
        cin>>x>>y>>d;
        for(int i=x;i<x+d;i++)
        {
            a[i][y]=-1;
        }
        if(x+d>xmax)xmax=x+d;
        if(y>ymax)ymax=y;

    }
    for(int j=1;j<=ymax;j++)
    {
        for(int i=0;i<=xmax;i++)
        {
            if(a[i][j]==0)b[i][j]=b[i][j-1];
            else
            {
                if(a[i-1][j]==0)b[i][j]=b[i-1][j]+1;
                else b[i][j]=b[i-1][j];
            }
            if(a[i][j]==0 and a[i-1][j]==1 and b[i-1][j]>b[i][j]+1)
            {
                b[i-1][j]=b[i][j]+1;
            int p=i-2;

            while(a[p][j]==1)
            {
                b[p][j]=b[p+1][j];
                p--;
            }
            }

        }
    }
    int T;
    cin>>T;
    for(int tt=1;tt<=T;tt++)
    {
        int t1;
        cin>>t1;
        cout<<b[t1][ymax]<<" ";
    }
    cout<<endl;
    return 0;
}
