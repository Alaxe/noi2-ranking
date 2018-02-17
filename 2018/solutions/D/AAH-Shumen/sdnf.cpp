#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int n,a[100][100];
void read()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
}
int main()
{
    int n;
    cin>>n;
    read();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    int t=a[0][n-1]+a[n-1][0]+a[1][n-1]+a[1][n-2]+a[n-2][n-2]+a[n-2][n-3]+a[n-1][1];
    cout<<t<<endl;


  return 0;
}
