#include<bits/stdc++.h>
using namespace std;
int n,m[105][105],i,j,sum,brx,bry=3;
char a,b;
int main()
{
    cin>>n;
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            cin>>a>>b;
            if (!isalpha(a)) m[i][j]=a-'0';
            else
            {
                if (a=='A') m[i][j]=1;
                if (a=='T') m[i][j]=10;
                if (a=='J') m[i][j]=11;
                if (a=='Q') m[i][j]=12;
                if (a=='K') m[i][j]=13;
            }
        }
    }
    for (i=n;i>=1;i--) m[i][1]=m[i][1]+m[i+1][1];
    for (i=1;i<=n;i++) m[n][i]=m[n][i]+m[n][i-1];

    i=n-1;j=2;brx=n-1;
    while (i>=1)
    {
        while (i!=n && j!=bry)
        {
            if (m[i+1][j]>m[i][j-1]) m[i][j]=m[i][j]+m[i+1][j];
            else m[i][j]=m[i][j]+m[i][j-1];

            i++;
            j++;
        }
        brx--;
        bry++;
        i=brx;
        j=2;
    }

    i=1;
    j=3;
    brx=3;

    while (j!=n+1)
    {
        while (j!=n+1)
        {
            if (m[i+1][j]>m[i][j-1]) m[i][j]=m[i][j]+m[i+1][j];
            else m[i][j]=m[i][j]+m[i][j-1];

            i++;
            j++;
        }
        brx++;
        i=1;
        j=brx;
    }

    cout<<m[1][n]<<endl;
}
/**
4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7H
TC QC AS 2D
*/
