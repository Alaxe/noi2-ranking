#include<bits/stdc++.h>
using namespace std;
string q="A23456789TJQK";
int main()
{
    string r;
    int s[102][102];
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>r;
            s[i][j]=q.find(r[0])+1;
        }
    }
    for(int k=0; k<n; k++)
    {
        for(int r=n-1; r>=0; r--)
        {
            if(k-1>=0 && r+1<n) s[r][k]=max(s[r+1][k],s[r][k-1])+s[r][k];
            else if(k-1>=0 && r+1>=n) s[r][k]=s[r][k-1]+s[r][k];
            else if(k-1<0 && r+1<n) s[r][k]=s[r+1][k]+s[r][k];
        }
    }
    cout<<s[0][n-1]<<endl;
}
