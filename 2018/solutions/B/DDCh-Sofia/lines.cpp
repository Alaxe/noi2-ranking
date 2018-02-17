#include <iostream>
#include <vector>
#include <utility>

typedef std::pair<int, int> point;

std::vector<point> v;
#define x first
#define y second

int oa(point a, point b, point c) {
    return (a.x+b.x)*(b.y-a.y)+(b.x+c.x)*(c.y-b.y)+(a.x+c.x)*(a.y-c.y);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    v.reserve(n);
    for(int i = 0 ; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        v.push_back({x, y});
    }
    int ans = 2;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int curr = 2;
            for(int k = j + 1; k < n; k ++) {
                if(oa(v[i], v[j], v[k]) == 0)
                    curr++;
            }
            if(curr > ans)
                ans = curr;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
