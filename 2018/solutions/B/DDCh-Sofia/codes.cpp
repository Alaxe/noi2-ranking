#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int n, k, a, b;

std::vector<char> dig;

bool comp(std::string a, std::string b) {
    if(a.size() > b.size())
        return true;
    return a > b;
}

int pow(int a, int b) {
    if(b == 0)
        return 1;
    if(b % 2)
        return a * pow(a, b - 1);
    return pow(a, b / 2) * pow(a, b / 2);
}

std::string gen(int ind, int num) {
    std::string ans = "";
    int plen = pow(n, num - 1);
    int digi = ind / plen;
    ans += dig[digi];
    if(num == 1)
        return ans;
    if(digi % 2 == 0) {
        ans += gen(ind % plen, num - 1);
    } else {
        ans += gen(plen - ind % plen -1, num - 1);
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> k >> a >> b;
    dig.resize(n);
    a--;
    b--;
    for(int i = 0; i < n; i++) {
        std::cin >> dig[i];
    }
    int maxd = 0;
    auto max = gen(a, k);
    int las = 0;
    for(auto &x: gen(a, k)) {
        las += x - '0';
    }
    for(int i = a + 1; i <= b; i++) {
        auto curr = gen(i, k);
        if(comp(curr, max))
            max = curr;
        int currs = 0;
        for(auto &x: curr)
            currs += x - '0';
        maxd = std::max(abs(las - currs), maxd);
        las = currs;
    }
    std::cout << max << " " << maxd << std::endl;
    return 0;
}
