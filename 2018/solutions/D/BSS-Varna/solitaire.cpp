#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[101][101]={0};
    int n;
    cin>>n;
    char k,ignore;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>k>>ignore;
            if(isdigit(k))a[i][j]=(k-'0');
            else if(k=='A')a[i][j]=1;
            else if(k=='T')a[i][j]=10;
            else if(k=='J')a[i][j]=11;
            else if(k=='Q')a[i][j]=12;
            else if(k=='K')a[i][j]=13;
        }
    }
    for(int i=1;i<n;i++)
    {
        a[n-1][i]=a[n-1][i-1]+a[n-1][i];
    }
    for(int i=n-2;i>=0;i--)
    {
        a[i][0]=a[i+1][0]+a[i][0];
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=1;j<=n-1;j++)
        {
            a[i][j]+=max(a[i+1][j],a[i][j-1]);
        }
    }
    cout<<a[0][n-1]<<endl;
}
/**
5
8S AD 3C AC TD
8C 4H QD QS KS
5D 9H KC 7H TH
TC QC AS 2D 7C
3D KD JC 9S KH
*/
