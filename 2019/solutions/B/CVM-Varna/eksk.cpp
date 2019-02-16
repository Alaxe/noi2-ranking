#include<bits/stdc++.h>
#define N 200001
using namespace std;
vector<int> v[N];
bool f[N];
int ans;
void rec(int a,int b,int br=1)
{
    if(a==b) return ;
    ans=max(ans,br);
    f[a]=f[b]=1;
    int sz1=v[a].size(),sz2=v[b].size();
    for(int i=0;i<sz1;i++)
    {
        if(f[v[a][i]]) continue;
        for(int j=0;j<sz2;j++)
        {
            if(f[v[b][j]]) continue;
            rec(v[a][i],v[b][j],br+1);
        }
    }
    f[a]=f[b]=0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x-1].push_back(y-1);
        v[y-1].push_back(x-1);
    }
    int a,b;
    cin>>a>>b; ans=1;
    rec(a-1,b-1);
    cout<<ans<<endl;
    return 0;
}
/**

6
1 2
2 3
3 4
4 5
5 6
4 5

8
1 2
2 3
3 4
2 5
5 6
3 7
7 8
1 8

*/
