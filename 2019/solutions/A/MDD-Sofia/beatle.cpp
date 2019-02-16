#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
struct plank {
    int x1;
    int x2;
};

struct level {
    int y;
    vector<plank> planks;

    int plank_at(int x) const {
        if(x < planks[0].x1)
            return -1;
        int l = 0, r = planks.size();
        while(l < r - 1) {
            int m = l + (r - l) / 2;
            if(planks[m].x1 > x)
                r = m;
            else
                l = m;
        }
        return x < planks[l].x2 ? l : -1;
    }

};

struct yplank {
    int x, y, d;
};

int shortest(const vector<level>& levels, int x, int lvl_idx) {
        if(lvl_idx == -1)
            return 0;
        const level& lvl = levels[lvl_idx];
        int pl_idx = lvl.plank_at(x);
        if(pl_idx == -1)
            return shortest(levels, x, lvl_idx - 1);
        const plank& pl = lvl.planks[pl_idx];
        return 1 + min(shortest(levels, pl.x1 - 1, lvl_idx - 1),
                       shortest(levels, pl.x2,     lvl_idx - 1));
}

int main() {
    vector<level> levels;
    int n;
    cin >> n;
    vector<yplank> yplanks;
    for(int i = 0; i < n; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        yplanks.push_back({x, y, d});
    }
    sort(begin(yplanks), end(yplanks), [](yplank& a, yplank& b){ return a.y != b.y ? a.y < b.y : a.x < b.x; });
    for(auto yp : yplanks) {
        if(levels.empty() || levels[levels.size() - 1].y < yp.y) {
            levels.push_back({yp.y, {}});
        }
        levels[levels.size() - 1].planks.push_back({yp.x, yp.x + yp.d});
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        cout << shortest(levels, x, levels.size() - 1) << ' ';
    }
}
