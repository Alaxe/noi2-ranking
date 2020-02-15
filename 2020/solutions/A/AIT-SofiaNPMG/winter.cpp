#include <bits/stdc++.h>
using namespace std;
long long n, m, ans = 0;
vector <pair <int, int> > adj [100005];
int d [100005], low [100005];
bool art [200005];
void dfs (int a, int idx){
    for (auto p : adj [a]){
        if (p.first == idx) continue;
        if (d [p.second] > 0) low [a] = min (low [a], low [p.second]);
        else{
            d [p.second] = d [a] + 1;
            low [p.second] = d [p.second];
            dfs (p.second, p.first);
            low [a] = min (low [a], low [p.second]);
            if (low [p.second] == d [p.second]) art [p.first] = 1;
        }
    }
}
bool vis [100005];
void bfs (int a){
    vis [a] = 1;
    queue <int> q;
    q.push (a);
    long long br = 0;
    while (!q.empty ()){
        a = q.front ();
        q.pop ();
        br ++;
        for (auto p : adj [a]){
            if (vis [p.second] || art [p.first]) continue;
            vis [p.second] = 1;
            q.push (p.second);
        }
    }
    ans += br * (br - 1) / 2;
}
int main (){

    ios::sync_with_stdio (false);
    cin.tie (0);

    cin >> n >> m;
    for (int i = 0; i < m; i ++){
        int u, v;
        cin >> u >> v;
        adj [u].push_back ({i, v});
        adj [v].push_back ({i, u});
    }
    d [1] = 1;
    low [1] = 1;
    dfs (1, -1);
    for (int i = 1; i <= n; i ++){
        if (!vis [i]) bfs (i);
    }
    cout << ans << '\n';

}
