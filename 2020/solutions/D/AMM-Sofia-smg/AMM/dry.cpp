#include <bits/stdc++.h>
using namespace std;
int m[103],s[103];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,j=0,ng,a,b,sb=0;
    cin>>n>>a>>b;
    for(i=0;i<n;i++)
    {
        cin>>m[i];
    }
    ng=m[0];
    for(i=1;i<n;i++)
    {
        if(ng<m[i])
        {
            ng=m[i];
            j=i;
        }
    }
    ng=m[0];
    for(i=0;i<=j;i++)
    {
        if(ng<m[i])
        {
            ng=m[i];
        }
        s[i]=ng;
    }
    ng=m[n-1];
    for(i=n-2;i>=j;i--)
    {
        if(ng<m[i+1])
        {
            ng=m[i+1];
        }
        s[i]=ng;
    }
    for(i=0;i<n-1;i++)
    {
        sb+=s[i]*a*b;
    }
    cout<<sb;
    return 0;
}
