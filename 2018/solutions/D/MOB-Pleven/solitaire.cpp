#include<iostream>
using namespace std;
int a[100][100];
int b[100][100];
int main()
{
int n;
cin>>n;
char c;
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
       cin>>c;
       if(c=='A')a[i][j]=1;
       else if(c=='2')a[i][j]=2;
       else if(c=='3')a[i][j]=3;
       else if(c=='4')a[i][j]=4;
       else if(c=='5')a[i][j]=5;
       else if(c=='6')a[i][j]=6;
       else if(c=='7')a[i][j]=7;
       else if(c=='8')a[i][j]=8;
       else if(c=='9')a[i][j]=9;
       else if(c=='T')a[i][j]=10;
       else if(c=='J')a[i][j]=11;
       else if(c=='Q')a[i][j]=12;
       else if(c=='K')a[i][j]=13;
       cin>>c;
    }
}

b[n-1][0]=a[n-1][0];
for(int i=n-2;i>=0;i--)
{
    b[i][0]=b[i+1][0]+a[i][0];
}
for(int i=1;i<n;i++)
{
    b[n-1][i]=b[n-1][i-1]+a[n-1][i];
}
for(int i=n-2;i>=0;i--)
{
    for(int j=1;j<n;j++)
    {
        b[i][j]=a[i][j]+max(b[i+1][j],b[i][j-1]);
    }
}
cout<<b[0][n-1];
return 0;
}/*
4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7H
TC QC AS 2D
*/
