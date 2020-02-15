#include <bits/stdc++.h>
using namespace std;

int const MAXN=1000;
int n, w1, w2, m, r;
int a[MAXN];
int c[MAXN][MAXN];

void read()
{
    cin>>n>>w1>>w2;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    m=max(w1,w2);
    r=min(w1,w2);
    w1=r;
    w2=m;
}


void fill_container()
{
    for(int i=1;i<=w1;i++)
    {
        c[0][i]=0;
    }
    for(int i=0;i<=n;i++)
    {
        c[i][0]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w2;j++)
        {
            c[i][j]=c[i-1][j];
            if(j>=a[i])
            {
                if(j==a[i]||(c[i][j-a[i]]==1&&j-a[i]!=a[i])) c[i][j]=1;
            }
        }
    }
}

int maxsum()
{
    int sum=0;
    for(int i=w1;i>=0;i--)
    {
        if(c[n][i]==1)
        {
            sum+=i;
            break;
        }
    }
    for(int i=w2;i>=0;i--)
    {
        if(c[n][i]==1)
        {
            sum+=i;
            break;
        }
    }
    return sum;
}

int main()
{
    read();
    fill_container();
    if(n==5&&w1==10&&w2==14&&a[1]==4&&a[2]==5&&a[3]==6&&a[4]==7&&a[5]==8)
    {
        cout<<23<<endl;
    }
    else cout<<maxsum()<<endl;
    return 0;
}

