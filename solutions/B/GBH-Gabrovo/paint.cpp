#include<iostream>
using namespace std;
int n,a[11005][11005],t,cur=1,down,r;
long long b[11005];
int main()
{
    cin>>r>>down;
    cin>>n;
    int x,y,w,h;
    for(int i=1;i<=n;i++) ///y ; x
    {
        cin>>x>>y>>w>>h;
        b[cur]=w*h;
        for(int i=y+1;i<=y+h;i++)
        {
            for(int j=x+1;j<=x+w;j++)
            {
                if(a[i][j]!=0)
                {
                    if(b[cur]<b[a[i][j]]) a[i][j]=cur;
                }///a[i][j]=cur;
                else a[i][j]=cur;
            }
        }
        cur++;
    }
   /* for(int i=1;i<=down;i++)
        {
            for(int j=1;j<=r;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }*/
    int br=0;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        cin>>x>>y;
        int check=a[y][x];
        for(int i=1;i<=down;i++)
        {
            for(int j=1;j<=r;j++)
            {
                if(a[i][j]==check) br++;
            }
        }
        cout<<br<<endl;
        br=0;
    }
    return 0;
}
