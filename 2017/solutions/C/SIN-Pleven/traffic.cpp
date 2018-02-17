#include<iostream>
#include<climits>
using namespace std;
int n,m,x,y,ans=INT_MAX;
struct matrix
{
    int sum=INT_MAX;
    char symbol;
}matrix[641][641];

int recursion (int x,int y,int sum)
{
    matrix[x][y].sum=sum;
    if (x==1 || x==n || y==1 || y==m) ans=min(ans,sum);
    else
    {
        if (sum + matrix[x+1][y].symbol - 'A' + 1 < matrix[x+1][y].sum && (matrix[x+1][y].symbol>='A' && matrix[x+1][y].symbol<='Z')) recursion(x+1,y,sum+matrix[x+1][y].symbol-'A'+1);
        if (sum + matrix[x-1][y].symbol - 'A' + 1 < matrix[x-1][y].sum && (matrix[x-1][y].symbol>='A' && matrix[x-1][y].symbol<='Z')) recursion(x-1,y,sum+matrix[x-1][y].symbol-'A'+1);
        if (sum + matrix[x][y+1].symbol - 'A' + 1 < matrix[x][y+1].sum && (matrix[x][y+1].symbol>='A' && matrix[x][y+1].symbol<='Z')) recursion(x,y+1,sum+matrix[x][y+1].symbol-'A'+1);
        if (sum + matrix[x][y-1].symbol - 'A' + 1 < matrix[x][y-1].sum && (matrix[x][y-1].symbol>='A' && matrix[x][y-1].symbol<='Z')) recursion(x,y-1,sum+matrix[x][y-1].symbol-'A'+1);
    }
}

int main ()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            cin>>matrix[i][j].symbol;
            if (matrix[i][j].symbol=='#') {x=i; y=j;}

        }
    recursion(x,y,0);
    cout<<ans<<endl;
    return 0;
}
/**
8 12
NY****AZ****
*SH*D**CHMW*
*CJ**G**LZO*
*JMS****NGG*
*JKPKN#YORC*
************
KJWWGDPLQMXL
TGLAKBQCRQSD
*/
