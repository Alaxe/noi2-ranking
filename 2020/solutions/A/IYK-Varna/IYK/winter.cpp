#include <bits/stdc++.h>

const int32_t MAX_N = 1e5;

struct Vertex {
    bool vis;
    int32_t dep, minDep;
    std::vector< int32_t > v;
};

Vertex g[MAX_N + 5], newG[MAX_N + 5];

void compute_cut_edges(int32_t v, int32_t par, int32_t dep) {
    g[v].dep = dep;
    g[v].minDep = dep;
    g[v].vis = true;

    for(auto &u : g[v].v) {
        if(!g[u].vis) {
            compute_cut_edges(u, v, dep + 1);
            g[v].minDep = std::min(g[v].minDep, g[u].minDep);
        }
        else if(u != par) {
            g[v].minDep = std::min(g[v].minDep, g[u].dep);
        }
    }
}

int32_t dfs(int32_t v) {
    int32_t comp = 1;
    newG[v].vis = true;

    for(auto &u : newG[v].v) {
        if(!newG[u].vis) {
            comp += dfs(u);
        }
    }

    return comp;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int32_t n, m;
    std::cin >> n >> m;

    std::vector< std::pair< int32_t, int32_t > > edges(m);
    for(int32_t i = 0; i < m; i++) {
        std::cin >> edges[i].first >> edges[i].second;
        g[edges[i].first].v.push_back(edges[i].second);
        g[edges[i].second].v.push_back(edges[i].first);
    }

    compute_cut_edges(1, -1, 0);

    for(int32_t i = 0; i < m; i++) {
        int32_t u = edges[i].first;
        int32_t v = edges[i].second;

        if(abs(g[u].dep - g[v].dep) != 1) {
            newG[v].v.push_back(u);
            newG[u].v.push_back(v);
            continue;
        }

        if(g[u].dep > g[v].dep) {
            if(g[u].minDep <= g[v].dep) {
                newG[u].v.push_back(v);
                newG[v].v.push_back(u);
            }
        }
        else {
            if(g[v].minDep <= g[u].dep) {
                newG[u].v.push_back(v);
                newG[v].v.push_back(u);
            }
        }
    }

    int64_t ans = 0;
    for(int32_t i = 1; i <= n; i++) {
        if(!newG[i].vis) {
            int32_t comp = dfs(i);
            if(comp > 1) {
                ans += ((int64_t) comp * (comp - 1)) / 2;
            }
        }
    }

    std::cout << ans << '\n';
}
