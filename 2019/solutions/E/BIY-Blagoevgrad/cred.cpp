#include  <bits/stdc++.h>

using namespace std;
int main()
{
    int n,m,d=0;
    cin>>n>>m;

    for ( int i=n; i<=m; i=i+i%10+i/10 )
    {
        d=d+1;
    }

    cout<<d<<endl;





     return 0;
}
