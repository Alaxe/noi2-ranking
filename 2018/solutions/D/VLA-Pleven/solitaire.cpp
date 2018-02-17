#include<iostream>
using namespace std;
int a[101][101],b[103][101];
int main()
{
    char c,d;
    int n,i,j,max1=0;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            cin>>c>>d;
            if(c=='A')a[i][j]=1;
            if(c=='2')a[i][j]=2;
            if(c=='3')a[i][j]=3;
            if(c=='4')a[i][j]=4;
            if(c=='5')a[i][j]=5;
            if(c=='6')a[i][j]=6;
            if(c=='7')a[i][j]=7;
            if(c=='8')a[i][j]=8;
            if(c=='9')a[i][j]=9;
            if(c=='T')a[i][j]=10;
            if(c=='J')a[i][j]=11;
            if(c=='Q')a[i][j]=12;
            if(c=='K')a[i][j]=13;
        }
    }
    for(i=1;i<=n;i++)
    {
        b[0][i]=0;
        b[n][i]=0;

    }
    for(i=1;i<=n;i++)
    {
        b[i][1]=a[i][1];
    }
    for(j=2;j<=n;j++)
    {
        for(i=n;i>=1;i--)
        {
         b[i][j]=max(b[i][j-1],b[i+1][j])+a[i][j];
        }
    }
    for(i=1;i<=n;i++)
    {
     if(b[i][n]>max1)max1=b[i][n];
    }

    cout<<max1<<endl;
    return 0;
}
/*
4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7H
TC QC AS 2D
*/
