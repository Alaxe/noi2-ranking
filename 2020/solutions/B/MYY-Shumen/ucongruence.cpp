#include<bits/stdc++.h>
using namespace std;
int n,u;
int a[1<<20];
int v[1<<20];
vector<vector<int> >vv;
void rec(int idx)
{
    if (idx==n+1)
    {
        bool ok=true;
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                if (a[i]==a[j])
                {
                    if (v[i]!=v[j])
                    {
                        ok=false;
                    }
                }
                if (a[i]>a[j])
                {
                    if (v[i]<=v[j])
                    {
                        ok=false;
                    }
                }
                if (a[i]<a[j])
                {
                    if (v[i]>=v[j])
                    {
                        ok=false;
                    }
                }
            }
        }
        if (ok)
        {
            vector<int>now;
            for (int i=1;i<=n;i++)
            {
                now.push_back(v[i]);
            }
            vv.push_back(now);
        }
        return ;
    }
    for (int j=1;j<=u;j++)
    {
        v[idx]=j;
        rec(idx+1);
        v[idx]=0;
    }
}
int main()
{

    cin>>n>>u;

    for (int i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    rec(1);

    sort(vv.begin(),vv.end());
    int N=(int)(vv.size());N/=2;

    for (int i=0;i<(vv[N].size());i++)
        cout<<vv[N][i]<<" ";
    cout<<endl;
    return 0;
}
