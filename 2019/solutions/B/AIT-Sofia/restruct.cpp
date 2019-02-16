#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
vector <int> v [5005];
bool used [5005];
long long bfs (int a){
    queue <pair <int, long long> > q;
    used [a] = 1;
    q.push ({a, 1ll});
    long long sum = 0ll;
    int br = 0;
    while (!q.empty ()){
        br ++;
        auto p = q.front ();
        q.pop ();
        sum += p.second;
        for (int i : v [p.first]){
            if (!used [i]){
                used [i] = 1;
                q.push ({i, p.second + 1ll});
            }
        }
    }
    if (br < n) return 1000000000000;
    return sum;
}
int main (){

    ios::sync_with_stdio (false);
    cin.tie (nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        int ki;
        cin >> ki;
        for (int j = 0; j < ki; j ++){
            int u;
            cin >> u;
            v [u].push_back (i);
        }
    }
    long long ans = 1000000000000;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++) used [j] = 0;
        ans = min (ans, bfs (i));
    }
    cout << ans * k << '\n';

    return 0;
}
