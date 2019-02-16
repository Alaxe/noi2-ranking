#include<iostream>
#include<vector>
using namespace std;
int n,m;
pair<int,int> p[100005];
int l;
vector<int> ans[50005];
vector<pair<int,int> > v[50005];
int tekbr=0;
bool edge[100005];
int k[50005];
void dfs (int br, int pos, vector<int> tekans)
{
    tekans.push_back(pos);
    if (br>tekbr)
    {
        ans[l]=tekans;
        tekbr=br;
    }

    for (int i=0; i<v[pos].size(); i++)
    {
        if (edge[v[pos][i].second])
            continue;

        //tekans.push_back(edge[v[pos][i].second]);
        edge[v[pos][i].second]=true;
        vector<int> o=tekans;
        o.push_back(v[pos][i].first);
        dfs(br+1,v[pos][i].second,o);
        edge[v[pos][i].second]=false;
    }
}
int main()
{
    cin>>n>>m;
    for (int i=0; i<m; i++)
    {
        cin>>p[i].first>>p[i].second;
        v[p[i].first].push_back(make_pair(p[i].second,i));
        v[p[i].second].push_back(make_pair(p[i].first,i));
        k[p[i].first]++;
        k[p[i].second]++;
    }
    while (true)
    {
        int pos=-1;
        for (int i=1; i<=n; i++)
            if (k[i]!=0)
            {
                pos=i;
                break;
            }
        if (pos==-1)
            break;

        cout<<pos<<'\n';

        tekbr=0;
        vector<int> q;
        dfs(1,pos,q);

        for (int i=0; i<ans[l].size(); i++)
            cout<<ans[l][i]<<' ';
        cout<<'\n';
        int o;
        cin>>o;
        for (int i=1; i<=n; i++)
            cout<<k[i]<<' ';
        cout<<'\n';

        for (int i=0; i<ans[l].size()-1; i++)
        {
            for (int j=0; j<v[ans[l][i]].size(); j++)
                if (v[ans[l][i]][i].first==ans[l][i+1])
                {
                    edge[v[ans[l][i]][i].second]=true;
                    k[v[ans[l][i]][i].first]--;
                    k[ans[l][i]]--;
                    break;
                }
        }

        l++;
    }

    cout<<l<<'\n';
    for (int i=0; i<l; i++)
    {
        cout<<ans[i].size()+1;
        for (int j=0; j<ans[i].size(); j++)
            cout<<ans[i][j]<<' ';
        cout<<'\n';
    }
}
