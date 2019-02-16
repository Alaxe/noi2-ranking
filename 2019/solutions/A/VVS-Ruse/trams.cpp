#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <utility>

#define endl '\n'

using namespace std;

const int N = 50003, M = 100003;

int n, m, x, y, last;
vector<int> v[N];
vector<int> paths[M];
unordered_set<int> used[N];

bool go(int curr) {
    paths[last].push_back(curr);
    bool fl = false;
    for(int i = 0; i < (int)v[curr].size(); ++i) {
        if(used[curr].find(v[curr][i]) == used[curr].end()) {
            used[curr].insert(v[curr][i]);
            used[v[curr][i]].insert(curr);
            fl = go(v[curr][i]);
            if(!fl) return fl;
        }
    }
    return fl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int goodsize = 0;
    for(int i = 1; i <= n; ++i) {
        go(i);
        if((int)paths[last++].size() > 1) goodsize++;
    }
    cout << goodsize << endl;
    for(int i = 0; i < last; ++i) {
        if((int)paths[i].size() < 2) continue;
        cout << (int)paths[i].size();
        for(int j = 0; j < (int)paths[i].size(); ++j) {
            cout << ' ' << paths[i][j];
        }
        cout << endl;
    }
    return 0;
}