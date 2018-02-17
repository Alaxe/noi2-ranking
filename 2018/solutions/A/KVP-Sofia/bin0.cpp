#include <iostream>

using namespace std;

long long s, t, izh;
int z;

bool check (int x) {
    int br = 0;
    while(x) {
        br += !(x % 2);
        if(br > z) return false;
        x /= 2;
    }
    if(br == z) return true;
    return false;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> t >> z;
    for(; s <= t; s ++) {
        izh += check(s);
    }
    cout << izh << endl;
    return 0;
}
