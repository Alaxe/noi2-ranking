#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct rect {
    int x, y, x1, y1, area;
    rect(int x, int y, int w, int h) {
        this -> x = x;
        this -> y = y;
        this -> x1 = w;
        this -> y1 = h;
        this-> area = (h-y) * (w-x);
    };
    bool inside(int x, int y) {
        return x >= this->x && x < this->x1 && y >= this->y && y < this->y1;
    }

    bool colide(rect &a) {
        return this->inside(a.x, a.y) || this->inside(a.x1, a.y1) || this-> inside(a.x, a.y1) || this->inside(a.x1, a.y);
    }

    int getCommon(rect &a) {
        int ans = -1;
        if(this->colide(a)) {
            int y = std::max(this->y, a.y);
            int y1 = std::min(this->y1, a.y1);
            int x = std::max(this->x, a.x);
            int x1 = std::min(this->x1, a.x1);
            ans = (x1-x) * (y1-y);
        }
        return (ans > 0) ? ans : 0;
    }
};

std::vector<rect> rects;

int w, h;

void dfs(int x, int y) {
    int where = 0;
    int aarea = 0;
    for(int i = 0 ; i < rects.size(); i++) {
        if(rects[i].inside(x, y))
            if(aarea == 0 || aarea > rects[i].area) {
                aarea = rects[i].area;
                where = i;
            }
    }
    std::queue<int> rm;
    for(int i = 1; i < rects.size(); i++) {
        if(i!= where) {
            aarea -= rects[where].getCommon(rects[i]);
            if(rects[where].colide(rects[i]))
                rm.push(i);
            }
    }
    while(!rm.empty()) {
        int i = rm.front();
        rm.pop();
        for(int j = 1; j < rects.size(); j++) {
            if(j != i && j != where && rects[j].colide(rects[i])) {
                aarea += rects[j].getCommon(rects[i]);
            }
        }
    }
    std::cout<< aarea << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> w >> h;
    int n;
    std::cin >> n;
    rects.reserve(n+1);
    rects.push_back(rect(0, 0, w, h));
    for(int i = 0; i < n; i++) {
        int X, Y, W, H;
        std::cin >> X >> Y >> W >> H;
        rects.push_back(rect(X, Y, X+W, Y+H));
    }
    int t;
    std::cin >> t;
    for(int q = 0; q < t; q++) {
        int x, y;
        std::cin >> x >> y;
        dfs(x, y);
    }
    return 0;
}
