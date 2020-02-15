#include<bits/stdc++.H>
using namespace std;
#define ll long long
ll pascal[64][64];
int main()
{
    pascal[0][0]=1;
    for(int i=1;i<50;i++)
    {
        pascal[i][0]=1;
        for(int j=1;j<=i;j++)
        {
            pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1];
        }
    }
    int n,m;
    cin>>n>>m;
    cout<<pascal[n-1][m-1]<<endl;
return 0;
}
