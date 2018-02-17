#include<iostream>
using namespace std;
int main()
{
    int n,m, kbn, kbm, ken, kem;
    cin>>n>>m;
    char sh[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>sh[i][j];
            if(sh[i][j]=='B') {kbn=i; kbm=j;}
            if(sh[i][j]=='E') {ken=i; kem=j;}
        }
    }
}
