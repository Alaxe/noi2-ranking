#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    long long a[n+1][m+1];
    for(int i=1;i<=n;i++)
    {
        a[i][1]=1;
    }
    for(int i=1;i<=m;i++)
    {
        a[0][i]=1;
        a[1][i]=1;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=m;j++)
        {
            a[i][j]=a[i][j-1];
            if(i>=j) a[i][j]+=a[i-j][j];
        }
    }
    cout<<a[n][m];
    return 0;
}
