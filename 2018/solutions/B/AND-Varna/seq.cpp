#include<bits/stdc++.h>
using namespace std;
long long n, m, i, j, mx[271][271];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(j==1 || i==1) mx[i][j] = 1;
	    else if(i==j) mx[i][j] = mx[i][j-1]+1;
	    else if(j>i) mx[i][j] = mx[i][j-1];
	    else mx[i][j] = mx[i][j-1] + mx[i-j][j];
	    //cout<<mx[i][j]<<" ";
        }
        //cout<<"\n";
    }
    cout<<mx[n][m]<<"\n";
    return 0;
}
