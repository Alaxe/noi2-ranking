#include <bits/stdc++.h>
using namespace std;
char a,b;
int maxbr=-1;
int br;
int s[101][101];
int n;
int main()
{
    cin>>n;
    for(int i=n-1; i>=0; i--)
    {
        for(int j=0; j<n; j++)
        {
            cin>>a>>b;
            if(a=='A')s[i][j]=1;
            else if(a=='T')s[i][j]=10;
            else if(a=='J')s[i][j]=11;
            else if(a=='Q')s[i][j]=12;
            else if(a=='K')s[i][j]=13;
            else s[i][j]=a-48;
        }
    }
    int i=0,j=0;
    while(i<=n && j<=n)
    {   br+=s[i][j];
        if(s[i+1][j]>s[i][j+1])
            i++;
        else j++;

    }
    cout<<br<<endl;
    return 0;
}
/*
4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7H
TC QC AS 2D
*/
