#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,a[100][100];
    char c;
    cin>>n;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cin>>c;
            if(c<'A')a[i][j]=c-'0';
            else if(c=='A')
            {
                a[i][j]=1;
            }
            else if(c=='T')
            {
                a[i][j]=10;
            }
            else if(c=='J')
            {
                a[i][j]=11;
            }
            else if(c=='Q')
            {
                a[i][j]=12;
            }
            else if(c=='K')
            {
                a[i][j]=13;
            }
            cin>>c;
        }
    }
    for(i=n-2; i>=0; i--)
    {
        a[i][0]+=a[i+1][0];
    }
    for(j=1; j<n; j++)
    {
        a[n-1][j]+=a[n-1][j-1];
    }

    for(i=n-2; i>=0; i--)
    {
        for(j=1; j<n; j++)
        {
            a[i][j]+=max(a[i+1][j],a[i][j-1]);
        }
    }
    cout<<a[0][n-1]<<endl;
}
/**
4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7H
TC QC AS 2D
*/
