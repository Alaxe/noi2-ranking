#include <bits/stdc++.h>
#define endl '\n'
#define left jhgqfhgeqkgeqj
#define right hquoiiueqfhqeuiu

using namespace std;

const int N = 100010, L = 0, R = 200005;
const int SIZE = 200010, TREE_SIZE = 800042;

struct platform {
  int from, to, y;

  bool operator <(const platform &a) const {
    return y < a.y;
  }
};

int n, q, left[N], right[N];
platform a[N];
int tree[TREE_SIZE], lazy[TREE_SIZE];
bool used[N];
int state[N];

void update_tree(int a, int b, int i, int j, int node, int value) {
  if(lazy[node]) {
    tree[node] = lazy[node];

    if(a!=b) {
      lazy[node<<1] = lazy[node];
      lazy[(node<<1)|1] = lazy[node];
    }

    lazy[node] = 0;
  }

  if(a>b || a>j || b<i) return;

  if(a>=i && b<=j) {
    tree[node] = value;

    if(a!=b) {
      lazy[node<<1] = value;
      lazy[(node<<1)|1] = value;
    }

    return;
  }

  update_tree(a, (a+b)>>1, i, j, node<<1, value);
  update_tree(((a+b)>>1) + 1, b, i, j, (node<<1)|1, value);
  tree[node] = max(tree[node<<1], tree[(node<<1)|1]);
}

int query_tree(int a, int b, int pos, int node) {
  if(a>b || a>pos || b<pos) return 0;

  if(lazy[node]) {
    tree[node] = lazy[node];

    if(a!=b) {
      lazy[node<<1] = lazy[node];
      lazy[(node<<1)|1] = lazy[node];
    }

    lazy[node] = 0;
  }

  if(a==b) return tree[node];

  return max(query_tree(a, (a+b)>>1, pos, node<<1), query_tree(((a+b)>>1)+1, b, pos, (node<<1)|1));
}

void update(int from, int to, int value) {
  update_tree(L, R, from, to, 1, value);
}

int query(int pos) {
  return query_tree(L, R, pos, 1);
}

int recurse(int last) {
  if(last==0) return 0;
  
  if(used[last]) return state[last];

  used[last] = true;
  return state[last] = 1 + min(recurse(left[last]), recurse(right[last]));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, x;

  scanf("%d", &n);
  for(i=1;i<=n;i++) {
    scanf("%d %d %d", &a[i].from, &a[i].y, &a[i].to);
    a[i].to += a[i].from - 1;
  }

  sort(a + 1, a + 1 + n);

  for(i=1;i<=n;i++) {
    left[i] = query(a[i].from - 1);
    right[i] = query(a[i].to + 1);
    update(a[i].from, a[i].to, i);
  }

  scanf("%d", &q);
  for(i=1;i<=q;i++) {
    scanf("%d", &x);

    if(i>1) printf(" ");
    printf("%d", recurse(query(x)));
  }
  printf("\n");

  return 0;
}
