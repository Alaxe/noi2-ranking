#include<iostream>
using namespace std;
int n;
int a[100000];
int m;
int b[100000][2];
int br[100000];
void read()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=2;j++)
        {
            cin>>b[i][j];
        }
    }
}
int main()
{
    read();
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]>=b[j][1]&&a[i]<=b[j][2])br[j]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<br[i]<<endl;
    }
    return 0;
}
/*
6
9 1 3 10 3 4
3
1 4
9 12
15 20
*/
