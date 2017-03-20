/*
ID: espr1t
TASK: Stories
KEYWORDS: Trivial, Iteration, Slow
*/

#include <cstdio>

FILE* in = stdin; FILE* out = stdout;
const int MAX = 10000001;

int n, k;
int a[MAX];

long long dummy() {
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int cur = a[i];
        for (int c = 1; c < k && i - c >= 0; c++)
            cur = cur < a[i - c] ? a[i - c] : cur;
        ans += cur;
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

    fprintf(out, "%lld\n", dummy());

    return 0;
}
