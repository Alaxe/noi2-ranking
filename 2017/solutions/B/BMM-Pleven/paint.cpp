#include<iostream>
using namespace std;
int a[11024][11024];
int main()
{
    int w, h, n, x1,x2,y1,y2,t,x,y;
    cin>>w>>h;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<n; j++)
        {
            a[i][j]=0;
        }
    }
    for(int i=1; i<=n; i++)
    {
        cin>>x1>>y1>>x2>>y2;
        int x3, y3;
        x3 =x1+x2;
        y3 =y1+y2;
        for(int j=x1; j<=x3; j++)
        {
            a[j][y1]=0;
            a[j][y3]=0;
        }
        for(int j=y1; j<=y3; j++)
        {
            a[x1][j]=0;
            a[x3][j]=0;
        }


    }

    cin>>t;
    for(int i=1; i<t; i++)
    {
        int brX1=0, brX2=0, brY1=0, brY2=0,brx=0,bry=0, br=0;
        cin>>x>>y;
        for(int j = x; ;j++)
        {
            if(a[j][y]!=1)
            {
                brX1++;
                cout<<brX1<<endl;
            }
        }
        for(int j = x; ;j--)
        {
            if(a[j][y]!=1)
            {
                brX2++;
                cout<<brX2<<endl;
            }
        }
        for(int j = y; ;j--)
        {
            if(a[x][j]!=1)
            {
                brY1++;
                cout<<brY1<<endl;
            }
        }
        for(int j = y; ;j++)
        {
            if(a[x][j]!=1)
            {
                brY2++;
                cout<<brY2<<endl;
            }
        }
        brx=brX1+brX2;
        bry=brY1+brY2;
        br = brx*bry;
        cout<<br<<endl;
    }

    return 0;
}
