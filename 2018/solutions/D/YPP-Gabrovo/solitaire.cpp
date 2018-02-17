#include<bits/stdc++.h>
using namespace std;

int a[105][105];
int n;

void Read()
{
    cin >> n;

    int i,j;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            string s;
            cin >> s;

            if(s[0]=='A') { a[i][j]=1; continue;}
            if('2'<=s[0] && s[0]<='9') { a[i][j]=s[0]-'0'; continue;}
            if(s[0]=='T') { a[i][j]=10; continue;}
            if(s[0]=='J') { a[i][j]=11; continue;}
            if(s[0]=='Q') { a[i][j]=12; continue;}
            if(s[0]=='K') { a[i][j]=13; continue;}
        }
}

void f()
{
    int i,j;
    for(i=n; i>0; i--)
        for(j=1; j<=n; j++)
            a[i][j]=max(a[i+1][j],a[i][j-1])+a[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Read();
    f();
    cout << a[1][n] << endl;

    return 0;
}
