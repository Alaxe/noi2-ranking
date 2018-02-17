#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

struct ots {
    pair <int, int> kr;
    int d;
};

int w, n, x, y, lx, ly, last;
long long s;
vector <pair <int, int> > used;
pair <int, int> help;
ots xy[100000];

bool comp(ots a, ots b) {
    return a.d < b.d;
}

int main() {
    scanf("%d %d %d %d %d", &w, &x, &n, &lx, &ly);
    for(int i = 1; i < n; i ++) {
        scanf("%d %d", &x, &y);
        if(lx == x) {
            xy[last].kr.first = min(y, ly);
            xy[last].kr.second = max(y, ly);
            xy[last].d = w - x;
            last ++;
        }
        lx = x;
        ly = y;
    }
    sort(xy, xy + last, comp);
    for(int i = 0; i < last; i ++) {
        for(int j = 0; j < used.size(); j ++) {
            if(used[j].first <= xy[i].kr.first && used[j].second >= xy[i].kr.second) {
                xy[i].kr.second = xy[i].kr.first;
                break;
            }
            if(used[j].first < xy[i].kr.first && used[j].second > xy[i].kr.first) {
                xy[i].kr.first = used[j].second;
                continue;
            }
            if(used[j].second > xy[i].kr.second && used[j].first < xy[i].kr.second) xy[i].kr.second = used[j].first;
        }
        s += (xy[i].kr.second - xy[i].kr.first) * xy[i].d;
        if(xy[i].kr.second != xy[i].kr.first) {
            help.first = xy[i].kr.first;
            help.second = xy[i].kr.second;
            used.push_back(help);
        }
    }
    printf("%lld\n", s);
    return 0;
}
