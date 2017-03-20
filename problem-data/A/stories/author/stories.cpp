/*
ID: espr1t
TASK: Stories
KEYWORDS: Medium, Ad-hoc, Buckets, Interviews
*/

#include <cstdio>
#include <algorithm>

using namespace std;
FILE* in = stdin; FILE* out = stdout;

const int MAX = 10000001;

int n, k;
int a[MAX];
int fwd[MAX], bck[MAX];

long long eval() {
    long long ans = 0;
    for (int i = 0; i < n; i++)
        fwd[i] = max(a[i], (i % k == 0 ? 0 : fwd[i - 1]));
    for (int i = n - 1; i >= 0; i--)
        bck[i] = max(a[i], (i % k == k - 1 ? 0 : bck[i + 1]));
    for (int i = 0; i < n; i++)
        ans += max(fwd[i], i - k + 1 < 0 ? 0 : bck[i - k + 1]);
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
