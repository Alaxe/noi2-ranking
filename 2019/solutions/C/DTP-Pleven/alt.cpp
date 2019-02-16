#include<iostream>
using namespace std;
long long i,j,p,q,n,m,k,s,a[101][101];
int main()
{
    cin>>k>>m>>n;
    m--;
    for(i=1;i<=m;i++)a[1][i]=1;
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(j+k<=m)a[i][j]+=a[i-1][j+k];
            if(j-k>0)a[i][j]+=a[i-1][j-k];
        }
    }
    for(i=1;i<=m;i++){s+=a[n][i];}
    cout<<s;
    return 0;
}
/*
1 49 49
10664256301561444
*/
