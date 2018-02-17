#include<iostream>

using namespace std;

int n;
int table[105][105];
long long maxtable[105][105];

int main()
{
    int a;
    cin>>n;
    string s;
    for(int i=0;i<n;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>s;
            if(s[0]>'0' && s[0]<='9') a=s[0]-'0';
            else if(s[0]=='T') a=10;
            else if(s[0]=='A') a=1;
            else if(s[0]=='J') a=11;
            else if(s[0]=='Q') a=12;
            else if(s[0]=='K') a=13;
            table[i][j]=a;
        }
    for(int i=n-1,j=1;j<=n;j++)
        maxtable[i][j]=maxtable[i][j-1]+table[i][j];
    for(int i=n-1,j=1;i>=0;i--)
        maxtable[i][j]=maxtable[i+1][j]+table[i][j];

    for(int i=n-2;i>=0;i--)
        for(int j=2;j<=n;j++)
        {
            maxtable[i][j]=max(maxtable[i+1][j],maxtable[i][j-1])+table[i][j];
        }
    cout<<maxtable[0][n]<<"\n";

    return 0;
}
/*
4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7H
TF QC AS 2D
*/
