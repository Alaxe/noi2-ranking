#include <bits/stdc++.h>
using namespace std;
const int maxn=131072;
const int maxa=2*1000006;
int w,k,an,bn,maxel;
int a[maxn],b[maxn];
vector<int>v[maxa];
///----------------------------------------------
void read()
{
    cin>>w>>k;
    cin>>an;
    for(int i=0; i<an; i++)
    {
        cin>>a[i];
        maxel=max(maxel,a[i]);
    }
    cin>>bn;
    for(int i=0; i<bn; i++)
    {
        cin>>b[i];
    }
}
///----------------------------------------------
void w2()
{
    long long int br=1,prev=a[0],ans=0;
    for(int i=1; i<an; i++)
    {
        if(a[i]==prev)
            br++;
        else
        {
            if(br>=k)
            {
                v[prev].push_back(br);
            }
            prev=a[i];
            br=1;
        }
    }
    if(br>=k)
    {
        v[prev].push_back(br);
    }
    br=1;
    prev=b[0];
    for(int i=1; i<bn; i++)
    {
        if(b[i]==prev)
            br++;
        else
        {
            if(br>=k)
            {
                if(v[prev].size()>0)
                {
                    for(int j=0; j<v[prev].size(); j++)
                    {
                        ans+=(br-k+1)*(v[prev][j]-k+1);
                    }
                }
            }
            br=1;
            prev=a[i];
        }
    }
    if(br>=k)
    {
        if(v[prev].size()>0)
        {
            for(int j=0; j<v[prev].size(); j++)
            {
                ans+=(br-k+1)*(v[prev][j]-k+1);
            }
        }
    }
    cout<<ans<<"\n";
    return;
}
///----------------------------------------------
void w1()
{
    long long int br=0,ans=0;
    for(int i=0;i<an;i++)
    {
        int prev=-1,br=0,ti=i;
        for(int j=0;j<bn;j++)
        {
            if(i==an)break;
            if(br==k)
            {
                prev=-1;
                br++;
                ti=i;
            }
            if(a[ti]==b[j] && prev<b[j])
            {
                prev=b[j];
                ti++;
                br++;
            }
            else
            {
                if(br>=k)
                {
                    ans++;
                }
                prev=-1;
                br=0;
                ti=i;
            }
        }
        if(br>=k)
        {
            ans++;
        }
    }
    cout<<ans<<"\n";
    return;
}
///----------------------------------------------
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    read();
    if(w==2)
    {
        w2();
    }
    else
    {
        w1();
    }
    return 0;
}
/*
2 3
11
3 4 4 4 4 5 7 6 6 6 6
16
3 6 6 6 4 4 4 5 6 6 6 7 7 6 6 6
*/
