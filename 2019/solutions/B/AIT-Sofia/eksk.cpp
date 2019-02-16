#include <bits/stdc++.h>
using namespace std;
int n, a, b;
vector <int> g [200005];
int par [200005];
bool marked [200005];
int maxdepth [200005];
int ansb [200005], ansa [200005];
int ans = 0;
int BR = 0;
void ROOT (int i){
    for (int j : g [i]){
        if (j != par [i]){
            par [j] = i;
            ROOT (j);
            maxdepth [i] = max (maxdepth [i], maxdepth [j]);
        }
    }
    maxdepth [i] ++;
}
void solveb (int i){
    if (i == -1) return;
    marked [i] = 1;
    BR ++;
    for (int j : g [i]){
        if (j != par [i] && !marked [j]){
            ansb [i] = max (ansb [i], maxdepth [j]);
        }
    }
    ansa [i] = ansb [i];
    ansb [i] = ansb [i] + BR;
    solveb (par [i]);
}
void solvea (int i){
    BR ++;
    for (int j : g [i]){
        if (j != par [i] && marked [j]){
            ans = max (ans, min (ansb [j], ansa [i] + BR));
            solvea (j);
        }
    }
}
int main (){

    ios::sync_with_stdio (false);
    cin.tie (nullptr);

    cin >> n;
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        g [u].push_back (v);
        g [v].push_back (u);
    }
    cin >> a >> b;
    par [a] = -1;
    ROOT (a);
    solveb (b);
    BR = 0;
    solvea (a);
    cout << ans << '\n';

    return 0;
}
