/*
ID: espr1t
TASK: Stories
KEYWORDS: Easy, Simple RMQ
*/

#include <cstdio>
#include <queue>

using namespace std;
FILE* in = stdin; FILE* out = stdout;

const int MAX = 10000001;

int n, k;
int a[MAX];

long long eval() {
    long long ans = 0;
    int treeSize = 1;
    while (treeSize < k)
        treeSize *= 2;
    treeSize *= 2;
    vector <int> tree(treeSize, 0);
    for (int i = 0; i < n; i++) {
        int idx = i % k + treeSize / 2;
        tree[idx] = a[i];
        for (idx = idx / 2; idx > 0; idx /= 2)
            tree[idx] = max(tree[(idx << 1) + 0], tree[(idx << 1) + 1]);
        ans += tree[1];
    }
    return ans;
}

int main(void) {
    // in = fopen("Stories.in", "rt");

    fscanf(in, "%d %d", &n, &k);
    int first, mul, add, mod;
    fscanf(in, "%d %d %d %d", &first, &mul, &add, &mod);
    a[0] = first;
    for (int i = 1; i < n; i++)
        a[i] = ((long long)a[i - 1] * mul + add) % mod;   

    fprintf(out, "%lld\n", eval());

    return 0;
}
