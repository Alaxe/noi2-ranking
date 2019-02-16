#include <bits/stdc++.h>

using namespace std;

const int N = 5e4;

vector<int> adj[N];
map<pair<int, int>, bool> is_edge;
int ind[N], cnt_left[N];
vector<int> cycle[N];
bool used[N];

void remove_edge(int u, int v){
    is_edge[make_pair(u, v)] = false;
    is_edge[make_pair(v, u)] = false;
    --cnt_left[u];
    --cnt_left[v];
}

vector<vector<int> > res;

void dfs(int u){
    vector<int> path;
    
    path.push_back(u);
    while(cnt_left[u]){
        while(ind[u] != (int)adj[u].size()){
            int to = adj[u][ind[u]];
            
            if(is_edge[make_pair(u,to)]){
                break;
            }
            ind[u]++;
        }
        
        int to = adj[u][ind[u]];
        
        remove_edge(u, to);
        ++ind[u];
        u = to;
        path.push_back(u);
    }
    
    res.push_back(path);
}

void dfs2(int u){
    int v = u;
    
    while(cnt_left[u]){
        while(ind[u] != (int)adj[u].size()){
            int to = adj[u][ind[u]];
            
            if(is_edge[make_pair(u,to)]){
                break;
            }
            ind[u]++;
        }
        
        int to = adj[u][ind[u]];
        
        remove_edge(u, to);
        ++ind[u];
        u = to;
        cycle[v].push_back(u);
    }
}

void dfs3(int u, vector<int> &v){
    used[u] = true;
    
    for(int x: cycle[u]){
        v.push_back(x);
        
        if(!used[x]){
            dfs3(x, v);
        }
    }
}

void dfs4(int u, vector<int> &v){
    bool placed = false;
    
    while(cnt_left[u]){
        while(ind[u] != (int)adj[u].size()){
            int to = adj[u][ind[u]];
            
            if(is_edge[make_pair(u,to)]){
                break;
            }
            ind[u]++;
        }
        
        int to = adj[u][ind[u]];
        
        remove_edge(u, to);
        ++ind[u];
        dfs4(to, v);
        v.push_back(u);
        placed = true;
    }
    if(!placed){
        v.push_back(u);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int n, m;
    
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int u, v;
        
        cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
        
        is_edge[make_pair(u, v)] = true;
        is_edge[make_pair(v, u)] = true;
        cnt_left[u]++;
        cnt_left[v]++;
    }
    
    for(int i = 1; i <= n; i++){
        while(cnt_left[i] % 2 == 1){
            dfs(i);
        }
    }
    
    if(res.empty()){
        vector<int> e;
        
        dfs4(1, e);
        
        res.push_back(e);
    }
    else{
        for(vector<int> &path: res){
            for(int x: path){
                if(cnt_left[x]){
                    dfs2(x);
                }
            }
        }
        
        for(vector<int> &path: res){
            vector<int> new_path;
            for(int x: path){
                new_path.push_back(x);
                
                if(!used[x] && !cycle[x].empty()){
                    dfs3(x, new_path);
                }
            }
            
            path = new_path;
        }
    }
    
    
    cout << res.size() << "\n";
    
    for(vector<int> path: res){
        cout << path.size();
        for(int node: path){
            cout << " " << node;
        }
        cout << "\n";
    }
    
    return 0;
}
/*
5 7
1 5
1 4
5 4
5 3
3 4
4 2
2 5
*/
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
*/
/*
10 14
4 6
4 1
1 5
1 7
1 3
4 8
6 10
6 2
6 9
7 8
2 5
4 3
1 9
8 1
*/
/*
16 1
7 13
7 16
13 12
12 3
16 11
16 5
5 1
1 10
10 15
1 14
12 4
12 6
6 8
16 2
12 9
*/