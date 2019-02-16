#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>v[50000],tree;
bool used[100000];
map<pair<int,int>,int>mp;
void Read()
{
    int a,b;
    cin>>n>>m;
    for(size_t i=0;i<m;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        mp.insert(make_pair(make_pair(a,b),i));
        mp.insert(make_pair(make_pair(b,a),i));
    }
}
int DFS(int curr)
{
    for(size_t i=0;i<v[curr].size();i++)
    {
        int temp=v[curr][i];
        if(used[mp.find(make_pair(curr,temp))->second]==false&&used[mp.find(make_pair(temp,curr))->second]==false)
        {
            tree.push_back(temp);
            used[mp.find(make_pair(curr,temp))->second]=true;
            used[mp.find(make_pair(temp,curr))->second]=true;
            DFS(temp);
            i=v[curr].size()+1;
        }
    }
}
int main()
{
    Read();
    cout<<m-n<<endl;
    DFS(1);
    cout<<tree.size()<<" ";
    cout<<1<<" ";
    for(int i=0;i<tree.size();i++)
    {
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    tree.clear();
    for(int i=0;i<n;i++)
    {
        int lamp=0;
        for(int j=0;j<v[i].size();j++)
        {
            if(used[mp.find(make_pair(i,v[i][j]))->second]==false)
            {
                lamp++;
            }
        }
        if(lamp==1)
        {
            DFS(i);
            cout<<tree.size()+1<<" ";
            cout<<i<<" ";
            for(int i=0;i<tree.size();i++)
            {
                cout<<tree[i]<<" ";
            }
            cout<<endl;
            tree.clear();
        }
    }
    return 0;
}
