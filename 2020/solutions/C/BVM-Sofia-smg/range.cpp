#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, m;
int x, y;
int cnt[maxn];
int prefix[maxn];
int main () {
    scanf("%d", &n);
    for (int i = 0 ; i < n ; ++i) {
        scanf("%d", &x);
        ++cnt[x];
    }
    for (int i = 1 ; i < maxn ; ++i) {
        prefix[i] += prefix[i-1] + cnt[i];
    }
    scanf("%d", &n);
    for (int i = 0 ; i < n ; ++i) {
        scanf("%d%d", &x, &y);
        printf("%d\n", (prefix[y] - prefix[x-1]));
    }
    return 0;
}
