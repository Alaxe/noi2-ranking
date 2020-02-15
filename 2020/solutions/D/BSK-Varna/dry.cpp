#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, u , v, a[107];
int rec( int i )
{
    int sum = 0;
    int b = i;
    for( i; i < n-1; i++)
    {
        if( a[i] > a[b] && a[i+1] < a[i] )
        {
            sum+=a[i]*u*v;
            if( a[i+1] < a[i] ) rec( i );
        }
        if( i == n-1 ) rec(i+1);
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> u >> v;
    for( int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum = 0;
    int b = 0;
    for( int i = 0; i < n; i++)
    {
        if( a[i] > a[b] && a[i+1] < a[i] )
        {
            cout << a[b]*u*v << endl;
            ///if( a[i+1] < a[i] ) rec( i );
        }
        if( i == n-1 ) rec(b+1);
    }
    cout << rec(0) << endl;
    return 0;
}
