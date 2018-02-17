#include <iostream>
using namespace std;
typedef long long ll;
ll t[3000][3000];

ll rec(int n,int m)
{
    if(n<m) m=n;
    if(t[n][m]!=0) return t[n][m];
    if(m==0) return 0;
    return t[n][m] = rec(n-m,m) + rec(n,m-1);
}

int main()
{
    int i,j,n,m;
    cin>>n>>m;
    for(j=0; j<=m; j++)
        t[0][j]=1;
    cout<<rec(n,m)<< endl;
    return 0;
}
/*
230793554364681
9253082936723602
6727090051741041926
*/
