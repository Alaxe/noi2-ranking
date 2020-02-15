#include<iostream>
#include<vector>
using namespace std;
int const maxn=100005;

int w;
int n,m,k;
int br[2000005];
int a[maxn],b[maxn];
vector<int>v[maxn];
int ans;

void solve()
{
    int i,j,cnt=1;
    for(i=1;i<n;i++)
    {
        if(a[i-1]<a[i])
            cnt++;
        else
            cnt=1;

        if(cnt>=k)
            v[a[i-k+1]].push_back(i-k+1);
    }

    for(i=0;i<m;i++)
    {
        int sz=v[b[i]].size();
        if(sz>0)
        {
            int ti,tj;
            for(j=0;j<sz;j++)
            {
                cnt=1;
                ti=i+1;
                tj=v[b[i]][j]+1;
                while(tj<n&&ti<m&&b[ti]==a[tj]&&b[ti-1]<b[ti])
                {
                    ti++;
                    tj++;
                    cnt++;
                    if(cnt>=k)
                        ans++;
                }
            }
        }

    }
}

int main()
{
    int i;

    cin>>w>>k;

    if(w==2)
    {
        cin>>n;
        cin>>a[0];
        int tbr;
        for(i=1;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==a[i-1])tbr++;
            else
            {
                if(tbr>=k)
                    br[a[i-1]]+=tbr-k+1;
                tbr=1;
            }
        }
        if(tbr>=k)
            br[a[i-1]]+=tbr-k+1;

        tbr=1;

        cin>>m;
        cin>>b[0];
        for(i=1;i<m;i++)
        {
            cin>>b[i];
            if(b[i]==b[i-1])tbr++;
            else
            {
                if(tbr>=k)
                    ans+=br[b[i-1]]*(tbr-k+1);
                tbr=1;
            }
        }
        if(tbr>=k)
            ans+=br[b[i-1]]*(tbr-k+1);
    }
    else
    {
        cin>>n;
        for(i=0;i<n;i++)
            cin>>a[i];

        cin>>m;
        for(i=0;i<m;i++)
            cin>>b[i];

        solve();

    }

    cout<<ans<<endl;

    return 0;
}
/*

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
