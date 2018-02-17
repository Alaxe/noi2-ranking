#include<iostream>
using namespace std;
int main()
{
    long long n,i,j,k,p,q,b[103][103],a[103][103];
    string s;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>s;
          if(s[0]=='A')a[i][j]=1;
          else  if(s[0]=='T')a[i][j]=10;
          else  if(s[0]=='J')a[i][j]=11;
          else  if(s[0]=='Q')a[i][j]=12;
          else  if(s[0]=='K')a[i][j]=13;
          else a[i][j]=s[0]-'0';
        }
    }


    for(i=1;i<=n;i++)
    {
        b[i][0]=0;
        b[n+1][i]=0;
    }
    for(j=1;j<=n;j++)
    {
        for(i=n;i>=1;i--)
        {
            b[i][j]=max(b[i][j-1],b[i+1][j])+a[i][j];
            //cout<<b[i][j]<<" ";
        }
        //cout<<endl;
    }
    cout<<b[1][n];
    return 0;
}
/*
4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7H
TC QC AS 2D
*/
