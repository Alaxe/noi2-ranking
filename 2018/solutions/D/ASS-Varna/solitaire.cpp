#include<bits/stdc++.h>
using namespace std;
int mas[100][100];
int main()
{
    string t;
    int n,i,j;
    cin>>n;
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
        {
            cin>>t;
            char c=t[0];
            if (c=='A') mas[i][j]=1;
            else if (c>='2'&&c<='9') mas[i][j]=int(c-'0');
            else if (c=='T') mas[i][j]=10;
            else if (c=='J') mas[i][j]=11;
            else if (c=='Q') mas[i][j]=12;
            else if (c=='K') mas[i][j]=13;
        }
    for (i=n-2; i>=0; i--) mas[i][0]+=mas[i-1][0];
    for (j=1; j<n; j++) mas[n-1][j]+=mas[n-1][j-1];
    ///
    for (i=n-2; i>=0; i--)
        for (j=1; j<n; j++)
        {
            mas[i][j]+=max(mas[i+1][j],mas[i][j-1]);
        }
    cout<<mas[0][n-1]<<endl;
    return 0;
}
/**
Input:
4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7H
TC QC AS 2D
Output:
69
*/
