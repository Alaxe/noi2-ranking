#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int a[100050],m,n,maxi=0,mini=2e9;
struct nakr
{
    int na,kr;
} b[100050];
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    memset(b,-1,sizeof(b));
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]>maxi)maxi=a[i];
        if(a[i]<mini)mini=a[i];
    }
    sort(a,a+n);
    for(int i=0; i<n; i++)
    {
        if(b[a[i]].na==-1)b[a[i]].na=i;
    }
    for(int i=n-1; i>=0; i--)
    {
        if(b[a[i]].kr==-1)b[a[i]].kr=i;
    }
    for(int i=mini; i<=maxi; i++)
    {
        if(b[i].kr==-1)b[i].kr=b[i-1].kr;
    }
    for(int i=maxi-1; i>=mini; i--)
    {
        if(b[i].na==-1)b[i].na=b[i+1].na;
    }
    cin>>m;
    for(int i=0; i<m; i++)
    {
        int l,r;
        cin>>l>>r;
        if((b[l].na==-1&&l>maxi)||(b[r].kr==-1&&r<mini))
        {
            cout<<0<<endl;
            continue;
        }
        if(b[r].kr==-1)b[r].kr=n-1;
        if(b[l].na==-1)b[l].na=0;
        cout<<b[r].kr-b[l].na+1<<endl;
    }
    return 0;
}
