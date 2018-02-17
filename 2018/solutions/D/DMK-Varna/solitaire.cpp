#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long i,j,n,sum=0,ch[200][200];
    cin>>n;
    string t;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            cin>>t;
            if (t[0]-'0'>=1 && t[0]-'0'<=9)ch[i][j]=t[0]-'0';
            if (t[0]=='T')ch[i][j]=10;
            if (t[0]=='A')ch[i][j]=1;
            if (t[0]=='J')ch[i][j]=11;
            if (t[0]=='Q')ch[i][j]=12;
            if (t[0]=='K')ch[i][j]=13;
        }
    }
    i=n-1;
    j=0;
    while (1)
    {
        if (ch[i][j+1]>=ch[i-1][j])
        {
            j++;
            sum+=ch[i][j];
        }
        else
        {
            i--;
            sum+=ch[i][j];
        }
        if (i==0 && j==n-1)break;
    }
    cout<<sum+ch[n-1][0]<<endl;
}

