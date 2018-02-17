#include<bits/stdc++.h>
using namespace std;
#define MAXN 102
int a[MAXN][MAXN],t[MAXN][MAXN];
int n;
int main()
{
    char c;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>c;
            if(isdigit(c))a[i][j]=c-'0';
            else
            {
                if(c=='A')a[i][j]=1;
                if(c=='T')a[i][j]=10;
                if(c=='J')a[i][j]=11;
                if(c=='Q')a[i][j]=12;
                if(c=='K')a[i][j]=13;
            }
            cin>>c;
        }
    }
    t[n-1][0]=a[n-1][0];
    for(int i=n-2;i>=0;i--)
    {
        t[i][0]=a[i][0]+t[i+1][0];
    }
    for(int j=1;j!=n;j++)
    {
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1){t[i][j]=t[i][j-1]+a[i][j];}
            else
            {
                t[i][j]=a[i][j]+max(t[i+1][j],t[i][j-1]);
            }
        }
    }
    cout<<t[0][n-1]<<endl;
return 0;
}
//100
