#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
long long a[MAXN],b[MAXN],ans,n,m,k,w;
int mp[2000005];
void read()
{
    cin>>w>>k;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    cin>>m;
    for(int i=1; i<=m; i++)
        cin>>b[i];
}
void solve1()
{
    for(int i=1; i<=n-k+1; i++)
    {
        for(int j=1; j<=m-k+1; j++)
        {
            int l=true;
            if(w==2)
            {
                for(int h=0; h<k-1; h++)
                {
                    if(a[i+h]!=a[i+h+1]||b[j+h]!=b[j+h+1])
                    {
                        l=false;
                        break;
                    }
                }
            }
            else if(w==1)
            {
                for(int h=0;h<k-1;h++)
                {
                    if(!(a[i+h]<a[i+h+1]&&b[j+h]<b[j+h+1]))
                    {
                        l=false;
                        break;
                    }
                }
            }
            if(l==true)
                for(int h=0; h<k; h++)
                {
                    if(a[i+h]!=b[j+h])
                    {
                        l=false;
                        break;
                    }
                }
           // if(l==1)cout<<i<<" "<<j<<endl;
            ans+=l;
        }
    }
    cout<<ans<<"\n";
}
void solve2()
{
    for(int i=1; i<=n-k+1; i++)
    {
        int d=a[i],l=1;
        for(int h=0; h<k-1; h++)
            if(a[i+h]!=a[i+h+1])
            {
                l=0;
                break;
            }
        if(l==1)
            mp[d]++;
    }
    for(int i=1; i<=m-k+1; i++)
    {
        int d=b[i],l=1;
        for(int h=0; h<k-1; h++)
            if(b[i+h]!=b[i+h+1])
            {
                l=0;
                break;
            }
        if(l==1)
            ans+=mp[d];
    }
    cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    read();
    if(k>m||k>n)
    {
        cout<<0<<"\n";
        return 0;
    }
    if(w==2)
        solve2();
    else
        solve1();
    return 0;
}
/**
2 3
11
3 4 4 4 4 5 6 6 6 6 7
16
3 6 6 6 4 4 4 5 6 6 6 7 7 6 6 6

1 2
6
2 1 3 4 3 6
6
3 6 1 3 6 7
*/
