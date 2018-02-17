#include <bits/stdc++.h>
using namespace std;
long long a[100][100], d, n, maxsum=0;
string s;
int rec(int i, int j, int l, int ts)
{
    if(l==d) if(ts>maxsum) maxsum=ts;
    if(i!=0) rec(i-1, j, l+1, ts+a[i-1][j]);
    if(j!=n-1) rec(i, j+1, l+1, ts+a[i][j+1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    d=2*n-2;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            cin>>s;
            if(s[0]=='A') a[i][j]=1;
            if(s[0]=='2') a[i][j]=2;
            if(s[0]=='3') a[i][j]=3;
            if(s[0]=='4') a[i][j]=4;
            if(s[0]=='5') a[i][j]=5;
            if(s[0]=='6') a[i][j]=6;
            if(s[0]=='7') a[i][j]=7;
            if(s[0]=='8') a[i][j]=8;
            if(s[0]=='9') a[i][j]=9;
            if(s[0]=='T') a[i][j]=10;
            if(s[0]=='J') a[i][j]=11;
            if(s[0]=='Q') a[i][j]=12;
            if(s[0]=='K') a[i][j]=13;

        }
    rec(n-1, 0, 0, a[n-1][0]);
    cout<<maxsum<<endl;
    return 0;
}
