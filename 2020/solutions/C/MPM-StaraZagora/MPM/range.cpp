#include <iostream>
#include <algorithm>
#include <vector>

int main () {
    int n;
    std::cin >> n;
    std::vector<int> range;
    for(int i = 0; i < n; i++) {
        int t;
        std::cin >> t;
        range.push_back(t);
    }
    std::sort(range.begin(), range.end());

    int m;
    std:: cin >> m;
    for(int i = 0; i < m; i++) {
        int a, b, s, e;
        std::cin >> a >> b;
        for(s = 0; range[s] < a; s++) ;
        for(e = 0; range[e] <= b; e++) ;
        std::cout << e - s << std::endl;
    }

    return 0;
}
