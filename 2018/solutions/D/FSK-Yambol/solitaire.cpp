#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int a[101][101],b[101][101],n,p,h=1;int j=0;
    string s[101];
    char d1='A',d2='2',d3='3',d4='4',d5='5',d6='6',d7='7',d8='8',d9='9',d10='T',d11='J',d12='Q',d13='K';
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int l=1;l<=n;l++)
            cin>>s[l];
        for(int l=1;l<n;l++)


            if(s[i][j]==d2)
                {a[i][h]=2;j=j+3;}
            if(s[i][j]==d3)
                {a[i][h]=3;j=j+3;}
            if(s[i][j]==d4)
                {a[i][h]=4;j=j+3;}
            if(s[i][j]==d5)
                {a[i][h]=5;j=j+3;}
            if(s[i][j]==d6)
                {a[i][h]=6;j=j+3;}
            if(s[i][j]==d7)
                {a[i][h]=7;j=j+3;}
            if(s[i][j]==d8)
                {a[i][h]=8;j=j+3;}
            if(s[i][j]==d9)
                {a[i][h]=9;j=j+3;}
            if(s[i][j]==d1)
                {a[i][h]=1;j=j+3;}
            if(s[i][j]==d10)
                {a[i][h]=10;j=j+3;}
            if(s[i][j]==d11)
                {a[i][h]=11;j=j+3;}
            if(s[i][j]==d12)
                {a[i][h]=12;j=j+3;}
            if(s[i][j]==d13)
                {a[i][h]=13;j=j+3;}
            h++;
        }
        h=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
/*
4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7H
TC QC AS 2D
*/
