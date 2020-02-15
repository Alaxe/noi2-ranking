#include <iostream>
#include <vector>

using namespace std;
void read();

const int kMaxN = 2e5 + 7;

int n, m;
vector<int> adj[kMaxN], adj_after[kMaxN];
pair<int, int> edges[kMaxN];
vector<pair<int, int> > removed_edges;

bool visited[kMaxN];
int time_in[kMaxN], min_time[kMaxN];
int curr_time = 0;

void dfs(int u, int parent = -1){
    min_time[u] = time_in[u] = curr_time++;
    visited[u] = true;

    for(int i = 0; i < adj[u].size(); ++i){
        int to = adj[u][i];
        if(to == parent)
            continue;
        if(visited[to]){
            min_time[u] = min(min_time[u], min_time[to]);
            continue;
        }

        dfs(to, u);
        if(min_time[to] > time_in[u])
            removed_edges.push_back(make_pair(to, u));
        min_time[u] = min(min_time[u], min_time[to]);
    }
}

void find_removed_edges(){
    for(int i = 0; i < m; ++i){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);
}

void find_remaining_edges(){
    for(int i = 0; i < m; ++i)
        if(edges[i].first > edges[i].second)
            swap(edges[i].first, edges[i].second);

    for(int i = 0; i < removed_edges.size(); ++i)
        if(removed_edges[i].first > removed_edges[i].second)
            swap(removed_edges[i].first, removed_edges[i].second);

    sort(edges, edges + m);
    sort(removed_edges.begin(), removed_edges.end());

    int edges_ptr = 0;
    for(int i = 0; i < removed_edges.size(); ++i){
        while(edges[edges_ptr] < removed_edges[i]){
            pair<int, int> edge = edges[edges_ptr];
            adj_after[edge.first].push_back(edge.second);
            adj_after[edge.second].push_back(edge.first);
            ++edges_ptr;
        }
        ++edges_ptr;
    }
    while(edges_ptr < m){
        pair<int, int> edge = edges[edges_ptr];
        adj_after[edge.first].push_back(edge.second);
        adj_after[edge.second].push_back(edge.first);
        ++edges_ptr;
    }
}

int dfs_cnt(int u){
    visited[u] = true;

    int ret = 1;
    for(int i = 0; i < adj_after[u].size(); ++i){
        int to = adj_after[u][i];
        if(visited[to])
            continue;

        ret += dfs_cnt(to);
    }

    return ret;
}

void solve(){
    find_removed_edges();
    find_remaining_edges();

    for(int i = 1; i <= n; ++i)
        visited[i] = false;

    long long ans = 0;
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            long long cnt = dfs_cnt(i);
            ans += cnt * (cnt - 1ll) / 2ll;
        }
    }

    cout << ans << "\n";
}

int main(){
    read();
    solve();
}

void read(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; ++i)
        cin >> edges[i].first >> edges[i].second;
}
