#include <bits/stdc++.h>
#define endl '\n'

#define SZ(x) ((int)x.size())
#define ALL(V) V.begin(), V.end()
#define L_B lower_bound
#define U_B upper_bound
#define pb push_back

using namespace std;
template<class T, class T1> int chkmax(T &x, const T1 &y) { return x < y ? x = y, 1 : 0; }
template<class T, class T1> int chkmin(T &x, const T1 &y) { return x > y ? x = y, 1 : 0; }
const int MAXN = (1 << 20);

int n, m, deg[MAXN];
vector<pair<int, int> > adj[MAXN];
pair<int, int> ed[MAXN];

void read()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
        deg[u]++;
        deg[v]++;
        ed[i] = {u, v};
    }
}

bool used[MAXN];
vector<pair<int, int> > path;

void dfs(int u)
{
    while(!adj[u].empty())
    {
        if(used[adj[u].back().second])
        {
            adj[u].pop_back();
            continue;
        }

        int v = adj[u].back().first, idx = adj[u].back().second;
        used[idx] = 1;
        deg[u]--, deg[v]--;
        dfs(v);
        if(idx < m) path.pb({v, u});
        else path.pb({-1, -1});
    }
}

void solve()
{
    vector<vector<int> > answer;

    int last_odd = -1;
    int idx = m;
    int cnt = 0;

    int bg = 1;
    for(int i = 1; i <= n; i++)
        if(deg[i] % 2 == 1)
        {
            if(last_odd == -1) last_odd = i;
            else
            {
                cnt++;
                if(cnt > 1)
                {
                    idx++;
                    adj[i].push_back({last_odd, idx});
                    adj[last_odd].push_back({i, idx});
                    deg[i]++, deg[last_odd]++;
                    ed[idx] = {i, last_odd};
                }
                else
                    bg = i;

                last_odd = -1;
            }
        }

    dfs(bg);

    vector<int> curr;
    for(pair<int, int> q: path)
    {
        if(q.first == -1)
        {
            answer.pb(curr);
            curr.clear();
        }
        else
        {
            if(curr.empty()) curr.pb(q.first);
            curr.pb(q.second);
        }
    }

    answer.pb(curr);

    cout << SZ(answer) << endl;
    for(auto vec: answer)
    {
        cout << vec.size() << " ";
        for(int ver: vec) cout << ver << " ";
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    read();
    solve();
    return 0;
}

/*
8 12
2 3
3 4
5 4
2 6
4 8
6 8
8 7
5 7
6 7
1 2
1 5
1 3

6 7
1 3
3 4
4 1
1 2
2 5
5 6
6 2
*/
