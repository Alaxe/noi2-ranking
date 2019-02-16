//#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "dwarfs"

#ifdef LOCAL
static struct __timestamper {
	~__timestamper(){
        TIMESTAMP(end);
	}
} __TIMESTAMPER;
#endif

typedef long long ll;
typedef long double ld;

const int MAXN = 310000;
const int inf = 1e9;

vector<int> g[MAXN];
int sv;
int ans;
int dst[MAXN];
int height[MAXN];

int dfs1(int v,int p){
    int& res = dst[v];
    res = -inf;
    for (int i = 0; i < (int)g[v].size(); i++)
        if (g[v][i] != p)
           res = max(res, dfs1(g[v][i], v) + 1);
    if (v == sv) return dst[v] = 0;
    return res;    
}

int dfs2(int v, int p){
    int& res = height[v];
    res = 0;
    for (int i = 0; i < (int)g[v].size(); i++)
        if (g[v][i] != p) {
           dfs2(g[v][i], v);
           if (dst[g[v][i]] < 0)
               res = max(res, height[g[v][i]] + 1);
        }
    if (v == sv) return -inf;
    return res;    
}

int main(){


  int n;
  scanf("%d",&n);

  for (int i = 0; i < n - 1; i++){
      int a, b;
      scanf("%d %d",&a, &b);
      --a, --b;
      g[a].pb(b);
      g[b].pb(a);
  }
  int st;
  scanf("%d %d",&st, &sv);
  --st, --sv;
  dfs1(st, -1);
  dfs2(st, -1);

//  for (int i = 0; i <  n; i++)
//  	eprintf("%d %d %d\n", i+1, dst[i], height[i]);

  int p = -1;
  int depth = 0;
  int best = 0;
  int v = st;
  while (v != sv){
      int next = -1;
      for (int i = 0; i < (int)g[v].size(); i++)
      	if (g[v][i] != p && dst[g[v][i]] >= 0){
      	    assert(next == -1);
      	    next = g[v][i];
      	}
      assert(next != -1);
      best = max(best, height[v] + depth);
//      eprintf("%d %d %d\n", v, best, height[next] + dst[next]);
      ans = max(ans, min(best, height[next] + dst[next]));
      p = v;
      v = next;
      depth++;
  }

  printf("%d\n", ans + 1);
  return 0;
}
