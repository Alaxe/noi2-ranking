#include <bits/stdc++.h>
using namespace std;
struct cards
{
    char s, c;
};
cards t[100][100];
int p[100][100];
int main()
{
    int n, i, j;
    cin >> n;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            cin >> t[i][j].s >> t[i][j].c;
            if (isdigit(t[i][j].s)) p[i][j]=(int)(t[i][j].s-'0');
            if (t[i][j].s=='A') p[i][j]=1;
            if (t[i][j].s=='T') p[i][j]=10;
            if (t[i][j].s=='J') p[i][j]=11;
            if (t[i][j].s=='Q') p[i][j]=12;
            if (t[i][j].s=='K') p[i][j]=13;
        }
    }
    for (i=n-2; i>=0; i--) p[i][0]=p[i][0]+p[i+1][0];
    for (i=1; i<n; i++) p[n-1][i]=p[n-1][i]+p[n-1][i-1];
    for (i=n-2; i>=0; i--)
    {
        for (j=1; j<n; j++)
        {
            p[i][j]+=max(p[i+1][j], p[i][j-1]);
        }
    }
    cout << p[0][n-1] << endl;
}
