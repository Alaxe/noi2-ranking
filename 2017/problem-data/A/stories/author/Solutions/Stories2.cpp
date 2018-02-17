/*
ID: espr1t
TASK: Stories
KEYWORDS: Medium, Ad-hoc, Hull, Interviews
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
    deque < pair <int, int> > q;
    for (int i = 0; i < n; i++) {
        while (!q.empty() && q.front().first <= a[i])
            q.pop_front();
        q.push_front(make_pair(a[i], i));
        while (i - q.back().second >= k)
            q.pop_back();
        ans += q.back().first;
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
