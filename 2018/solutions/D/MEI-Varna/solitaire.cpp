//It isn't Polytopia but it will have to do.
#include <iostream>
using namespace std;
int a[100][100];
int main()
{
    int n,i,j;
    string s;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>s;
            if(s[0]=='T') a[i-1][j-1]=10;
            else if(s[0]=='J') a[i-1][j-1]=11;
            else if(s[0]=='Q') a[i-1][j-1]=12;
            else if(s[0]=='K') a[i-1][j-1]=13;
            else if(s[0]=='A') a[i-1][j-1]=1;
            else a[i-1][j-1]=s[0]-'0';
        }
    }
    for(i=1;i<n;i++)
    {
        a[n-1][i]=a[n-1][i-1]+a[n-1][i];
        a[n-i-1][0]=a[n-i][0]+a[n-i-1][0];
    }
    for(i=n-2;i>=0;i--)
    {
        for(j=1;j<n;j++)
        {
            if(a[i][j-1]>a[i+1][j]) a[i][j]=a[i][j]+a[i][j-1];
            else a[i][j]=a[i][j]+a[i+1][j];
        }
    }
    cout<<a[0][n-1]<<endl;
}
