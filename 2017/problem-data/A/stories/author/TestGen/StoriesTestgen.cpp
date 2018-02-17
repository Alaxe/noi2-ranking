/*
ID: espr1t
TASK: Stories
KEYWORDS: Testgen
*/

#include <cstdio>
#include <queue>
#include <ctime>
#include <vector>
#include <unordered_map>

using namespace std;
const int MAX = 10000001;

int n, k;
int a[MAX];

long long eval4() {
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

long long eval3() {
    long long ans = 0;
    priority_queue < pair <int, int> > q;
    for (int i = 0; i < n; i++) {
        q.push(make_pair(a[i], i));
        while (i - q.top().second >= k)
            q.pop();
        ans += q.top().first;
    }
    return ans;
}

long long eval2() {
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

long long eval1() {
    long long ans = 0;
    vector <int> fwd(n + 1, 0);
    for (int i = 0; i < n; i++)
        fwd[i] = max(a[i], (i % k == 0 ? 0 : fwd[i - 1]));
    vector <int> bck(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
        bck[i] = max(a[i], (i % k == k - 1 ? 0 : bck[i + 1]));
    for (int i = 0; i < n; i++)
        ans += max(fwd[i], i - k + 1 < 0 ? 0 : bck[i - k + 1]);
    return ans;
}

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

long long runSolutions() {
    double sTime;
    long long ans;

    if ((long long)n * k < 1000000000LL) {
        sTime = clock();
        ans = dummy();
        fprintf(stdout, "%lld (%.3lfs)\n", ans, (clock() - sTime) / CLOCKS_PER_SEC);
    }

    sTime = clock();
    ans = eval1();
    fprintf(stdout, "%lld (%.3lfs)\n", ans, (clock() - sTime) / CLOCKS_PER_SEC);

    sTime = clock();
    ans = eval2();
    fprintf(stdout, "%lld (%.3lfs)\n", ans, (clock() - sTime) / CLOCKS_PER_SEC);

    sTime = clock();
    ans = eval3();
    fprintf(stdout, "%lld (%.3lfs)\n", ans, (clock() - sTime) / CLOCKS_PER_SEC);

    sTime = clock();
    ans = eval4();
    fprintf(stdout, "%lld (%.3lfs)\n", ans, (clock() - sTime) / CLOCKS_PER_SEC);
    
    return ans;
}

void generateInput(int n, int k, int first, int mul, int add, int mod) {
    ::n = n, ::k = k;
    a[0] = first;
    for (int i = 1; i < n; i++)
        a[i] = ((long long)a[i - 1] * mul + add) % mod;
    fprintf(stderr, "First few: ");
    for (int i = 0; i < 5; i++)
        fprintf(stderr, "%d%c", a[i], i + 1 == 5 ? '\n' : ' ');
    
    unordered_map <int, int> q;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (q.find(a[i]) != q.end()) {
            fprintf(stderr, "Cycle length: %d\n", i - q[a[i]]);
            found = true;
            break;
        }
        q[a[i]] = i;
    }
    if (!found)
        fprintf(stderr, "All unique!\n");
    fprintf(stderr, "Number of distinct elements: %d\n", (int)q.size());
    
    //for (int i = 0; i < n; i++)
    //    fprintf(stderr, "%d%c", a[i], i + 1 == n ? '\n' : ' ');
}

int main(void) {
    vector < vector <int> > tests;
    
    // Sample Input 1
    tests.push_back({7, 3, 5, 3, 2, 23});

    // Sample Input 2
    tests.push_back({133742, 666, 20, 3, 17, 1000000007});
    
    // Small Test 1
    tests.push_back({4242, 17, 81, 5, 1, 1000003});

    // Small Test 2
    tests.push_back({66642, 1337, 12, 11, 91, 1000003});

    // Small Test 3
    tests.push_back({123456, 131, 12, 2, 177, 1000000});

    // Small Test 4
    tests.push_back({333333, 333, 3, 33, 333, 333333333});
    
    // Small Test 5
    tests.push_back({333333, 333, 3, 33, 333, 333333313});

    // Small Test 6
    tests.push_back({98765, 4321, 123, 456, 789, 123456789});

    // Small Test 7
    tests.push_back({12121, 12121, 121, 121, 121, 121212121});

    // Small Test 8
    tests.push_back({1000000, 100, 1, 10, 0, 1000000000});

    // Small Test 9
    tests.push_back({20000, 10000, 1000000000, 999999999, 999999998, 1000000007});

    // Large Test 1
    tests.push_back({2000000, 1000000, 1000000000, 999999999, 999999998, 1000000007});

    // Large Test 2
    tests.push_back({1000000, 100000, 1000000000, 999999999, 999999998, 1000000003});

    // Large Test 3
    tests.push_back({5000000, 1000000, 13, 17, 1, 1000000007});

    // Large Test 4
    tests.push_back({10000000, 1000000, 42, 1713, 11, 1000000007});
    
    // Large Test 5
    tests.push_back({10000000, 1000000, 123, 456, 789, 123456789});

    // Cycle with size K
    tests.push_back({10000000, 27968, 123, 456, 789, 12345678});
    
    // Increasing with size K
    tests.push_back({10000000, 100000, 0, 1, 10001, 1000000000});

    // All equal
    tests.push_back({10000000, 5555555, 1000000000, 1, 0, 1000000001});
    
    // Increasing
    tests.push_back({10000000, 1000001, 1, 1, 1, 1000000001});
    
    // Decreasing
    tests.push_back({10000000, 999999, 1000000000, 1, 1000000000, 1000000001});

    for (int t = 0; t < (int)tests.size(); t++) {
        if (t > 0) fprintf(stderr, "\n");
        fprintf(stderr, "Solving testcase %d...\n", t);
        generateInput(tests[t][0], tests[t][1], tests[t][2], tests[t][3], tests[t][4], tests[t][5]);
        
        long long ans = runSolutions();
        
        char inpFile[32];
        sprintf(inpFile, "Stories.%02d.in", t);
        FILE* inp = fopen(inpFile, "wt");
        fprintf(inp, "%d %d\n", tests[t][0], tests[t][1]);
        fprintf(inp, "%d %d %d %d\n", tests[t][2], tests[t][3], tests[t][4], tests[t][5]);
        fclose(inp);

        char solFile[32];
        sprintf(solFile, "Stories.%02d.sol", t);
        FILE* sol = fopen(solFile, "wt");
        fprintf(sol, "%lld\n", ans);
        fclose(sol);
    }

    return 0;
}
