#include <iostream>
#include<vector>
#include <map>

int n, m;
std::map<unsigned long long, bool> mem;

unsigned long long hash(std::vector<short> &q) {
    unsigned long long ans = 0;
    for(auto &x: q) {
        ans = (ans * (m+1) + x) % 1000000007;
    }
    return ans;
}

int brum(std::vector<short> red) {
    if(mem[hash(red)])
        return 0;
    std::vector<short> tmp;
    int ans = 1;
    if(red.size() > 1 && red[0] + red[1] <= m) {
        tmp.resize(red.size() - 1);
        tmp[0] = red[0] + red[1];
        for(int i = 2; i < red.size(); i++)
            tmp[i-1] = red[i];
        ans += brum(tmp);
    }
    for(int i  = 1 ; i < red.size() - 1; i++) {
        if(red[i] + red[i+1] <= m && red[i] + red[i+1] <= red[i-1]) {
            tmp.clear();
            tmp.reserve(red.size() - 1);
            for(int j = 0; j < i; j++) {
                tmp.push_back(red[j]);
            }
            tmp.push_back(red[i] + red[i+1]);
            for(int j = i + 2; j < red.size(); j++)
                tmp.push_back(red[j]);
            ans += brum(tmp);
        }
    }
    mem[hash(red)] = true;
    return ans;
}


int main() {
    std::cin >> n >> m;
    std::vector<short> sv;
    sv.resize(n);
    for(int i = 0; i < n; i++)
        sv[i] = 1;
    std::cout << brum(sv) << std::endl;
    return 0;
}
