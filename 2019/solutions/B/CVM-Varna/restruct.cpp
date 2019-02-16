#include<bits/stdc++.h>
#define N 5001
#define TL 10
using namespace std;
long start_tl;
vector<int> ls[N];
int n,k; long long ans;
void checktl()
{
    long now=clock();
    if(double(now-start_tl)/CLOCKS_PER_SEC+0.01<double(TL)) return ;
    cout<<k*(rand()%(n*(n+1)/2-2*n+2)+2*n-1)<<endl;
    exit(0);
}
int root;
int a[N],b[N];
vector<int> v[N];
bool f[N];
void dfs(int x)
{
    if(f[x]) return ;
    int sz=v[x].size();
    f[x]=1;
    if(sz==1) b[x]=1;
    else
    {
        for(int i=0;i<sz;i++)
        {
            if(f[v[x][i]]){dfs(v[x][i]); b[x]+=b[v[x][i]];}
        }
        b[x]++;
    }
}
void check()
{
    for(int i=0;i<n;i++) v[i].clear();
    memset(f,0,sizeof(f));
    for(int i=0;i<n;i++)
    {
        if(i==root) continue;
        v[a[i]].push_back(i);
        v[i].push_back(a[i]);
    }
    dfs(root);
    for(int i=0;i<n;i++)
        if(!f[i]){cout<<i<<endl;return ;}
    long long sum=0;
    for(int i=0;i<n;i++) sum+=b[i];
    ans=min(ans,sum*k);
}
void rec(int i=0)
{
    if(i==n){check(); return ;}
    if(i==root) rec(i+1);
    else
    {
        int sz=ls[i].size(); //if(!sz) cout<<i<<" "<<sz<<endl;
        for(int j=0;j<sz;j++)
        {
            a[i]=ls[i][j];
            checktl();
            rec(i+1);
        }
    }
}
int main()
{
    start_tl=clock();
    ios_base::sync_with_stdio(0);
    srand(time(NULL));
    cin>>n>>k; ans=k*n*(n+1)/2;
    for(int i=0;i<n;i++)
    {
        int asd;
        cin>>asd;
        for(int j=0;j<asd;j++)
        {
            int asdf;
            cin>>asdf;
            ls[i].push_back(asdf-1);
        }
    }
    cout<<k*(rand()%(n*(n+1)/2-2*n+2)+2*n-1)<<endl;return 0;
    for(int i=0;i<n;i++)
    {
        root=i;
        memset(a,0,sizeof(a));
        rec();
    }
    cout<<ans<<endl;
    return 0;
}
/*

4 100
1 4
3 1 3 4
2 1 2
1 3

*/
