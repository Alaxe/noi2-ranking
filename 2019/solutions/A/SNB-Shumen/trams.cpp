#include<bits/stdc++.h>
#define maxn int(1e4+5)
#define maxm int(1e5+5)
using namespace std;
int n;
int cnt[maxn];
bool used[maxn][maxn];
vector<int>v[maxn];

void read()
{
    int m,i,x,y;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        cnt[x]++;
        cnt[y]++;
        v[x].push_back(y);
        v[y].push_back(x);
    }
}

int find_min()
{
    int i,mn=900001,idx=-1;
    for(i=1;i<=n;i++)
        if(cnt[i]>0&&mn>cnt[i])
        {
            mn=cnt[i];
            idx=i;
        }
    return idx;
}

int index;
vector<int>ans[maxm];
void DFS(int i)
{
    int sz=v[i].size(),j,mx=0,idx;
    ans[index].push_back(i);
    for(j=0;j<sz;j++)
    {
        int nb=v[i][j];

        if(!used[i][nb])
        {
            if(mx<cnt[nb])
            {
                mx=cnt[nb];
                idx=j;
            }
        }
    }
    if(mx==0)return ;
    idx=v[i][idx];
    used[i][idx]=true;
    used[idx][i]=true;
    cnt[i]--;cnt[idx]--;
    DFS(idx);
}

void solve()
{
    int k=0,mn=find_min();
    while(mn!=-1)
    {
        k++;
        DFS(mn);
        index++;
        mn=find_min();
    }
}

void print_ans()
{
    int i,j,sz;
    cout<<index<<endl;
    for(i=0;i<index;i++)
    {
        sz=ans[i].size();
        cout<<sz;
        for(j=0;j<sz;j++)
            cout<<" "<<ans[i][j];
        cout<<endl;
    }
}

int main()
{
    read();
    solve();
    print_ans();
	return 0;
}
