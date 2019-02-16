#include<bits/stdc++.h>
using namespace std;
const MAX_N=50005;
int n, m;
vector<int> v[MAX_N], tree;
bool used[2*MAX_N];
map<pair<int, int>, int> mp;
void read()
{
    int a, b;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++)
    {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
        mp.insert(make_pair(make_pair(a, b), i));
        mp.insert(make_pair(make_pair(b, a), i));
    }
}
int DFS(int curr)
{
    for(int i=0; i<v[curr].size(); i++)
    {
        int temp=v[curr][i];
        if(used[mp.find(make_pair(curr, temp)->second)]==false&&used[mp.find(make_pair(temp, curr)->second)]==false)
        {
            cout<<temp<<" ";
            used[mp.find(make_pair(curr, temp)->second)]=true;
            used[mp.find(make_pair(temp, curr)->second)]=true;
            DFS(temp);
        }
    }
}
void solve()
{
    cout<<m-n<<endl;
    for(int i=1; i<=n; i++)
        for(int j=0; j<v[i].size(); i++)
            if(used[mp.find(make_pair(i, v[i][j])->second)]==false)
                DFS(i);
}
int main()
{
    read();
    solve();
    return 0;
}
