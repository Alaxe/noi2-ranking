#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int N = 50007;

struct path_t {
  int u, v, lca;

  path_t(int a = 0, int b = 0, int c = 0): u(a), v(b), lca(c) {}
};

int n, m, parent[N];
vector < int > v[N];
set < int > s[N];
bool is_odd[N];
vector < vector < int > > ans;
bool used[N];
vector < path_t > paths;
vector < int > path;

int dfs_tree(int node) {
  int i, ans = 0;
  vector < int > g;

  used[node] = true;
  for(i=0;i<(int)(v[node].size());i++) {
    if(!used[v[node][i]]) {
      parent[v[node][i]] = node;
      
      int ret = dfs_tree(v[node][i]);
      if(ret>0) g.push_back(ret);
    }
  }

  if(is_odd[node]) g.push_back(node);

  if(g.size()%2==0) {
    for(i=0;i<(int)(g.size());i+=2) {
      paths.push_back(path_t(g[i], g[i + 1], node));
    }
  }
  else {
    ans = g.back();
    g.pop_back();
    for(i=0;i<(int)(g.size());i+=2) {
      paths.push_back(path_t(g[i], g[i + 1], node));
    }
  }

  return ans;
}

void remove_edge(int x, int y) {
  s[x].erase(y);
  s[y].erase(x);
}

void generate_path(path_t p) {
  int i, n1 = p.u, n2 = p.v, lca = p.lca;
  vector < int > p1, p2;

  while(n1!=lca) {
    p1.push_back(n1);
    remove_edge(n1, parent[n1]);
    n1 = parent[n1];
  }

  while(n2!=lca) {
    p2.push_back(n2);
    remove_edge(n2, parent[n2]);
    n2 = parent[n2];
  }

  p1.push_back(lca);
  reverse(p2.begin(), p2.end());
  for(i=0;i<(int)(p2.size());i++) {
    p1.push_back(p2[i]);
  }

  ans.push_back(p1);
}

void euler(int node) {
  while(!s[node].empty()) {
    int curr = *s[node].begin();
    
    remove_edge(node, curr);
    euler(curr);
  }

  path.push_back(node);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, j, x, y;

  scanf("%d %d", &n, &m);
  for(i=1;i<=m;i++) {
    scanf("%d %d", &x, &y);
    
    v[x].push_back(y);
    v[y].push_back(x);
    
    s[x].insert(y);
    s[y].insert(x);
  }

  for(i=1;i<=n;i++) {
    if(v[i].size()%2==1) {
      is_odd[i] = true;
    }
  }

  assert(dfs_tree(1)==0);

  if(paths.size()>0) {
    for(i=1;i<(int)(paths.size());i++) {
      generate_path(paths[i]);
    }

    euler(paths[0].u);
    ans.push_back(path);
  
    for(i=1;i<=n;i++) {
      path.clear();
      euler(i);
      if(path.size()>1) ans.push_back(path);
    }
  }
  else {
    for(i=1;i<=n;i++) {
      path.clear();
      euler(i);
      if(path.size()>1) ans.push_back(path);
    }
  }

  printf("%d\n", (int)(ans.size()));
  for(i=0;i<(int)(ans.size());i++) {
    printf("%d", (int)(ans[i].size()));
    for(j=0;j<(int)(ans[i].size());j++) {
      printf(" %d", ans[i][j]);
    }
    printf("\n");
  }

  return 0;
}
