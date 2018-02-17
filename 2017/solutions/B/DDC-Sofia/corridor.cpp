#include <iostream>
#include <algorithm>

int main() {
    int w, h;
    std::cin >> w >> h;
    int n;
    std::cin >> n;
    int ans = 0;
    int lastX, lastY, maxX, maxT = 0, maxF = 0;
    std::cin >> lastX >> lastY;
    maxX = lastX;
    for(int i = 1; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        maxX = std::max(maxX , x);
        if(maxX == x) {
            maxT = y;
            maxF = lastY;
        }
        if(y != lastY && y >= maxT) {
            ans += (maxT - maxF) * (w - maxX);
            ans += (y - maxT) * (w - x);
            maxX = x;
            maxF = maxT;
            maxT = y;
        } else if(y > lastY)
            ans += (y - lastY) * (w - x);
        lastY = y;
        lastX = x;
    }
    std::cout << ans << std::endl;
    return 0;
}
