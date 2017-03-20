#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 1001
#define mod 123456789012345

using namespace std;

int n;
struct masiv {
    int value;
    int index;
} a[MAXN], a1[MAXN];
unsigned long long answer;

bool tmp(const masiv &a, const masiv &b) {
    return a.value < b.value;
}

int binSearch(int key, int length) {
    int l = 0, r = length - 1;

    while (l <= r) {
        int m = (l + r) / 2;
        if (a1[m].value > key) r = m - 1;
        else if (a1[m].value < key) l = m + 1;
        else return a1[m].index;
    }

    return -1;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].value);
        a[i].index = i;
        a1[i].value = a[i].value;
        a1[i].index = i;
    }

    sort(a1, a1+n, tmp);

    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j].value <= a[i].value) continue;
            int p1 = a[i].value, p2 = a[j].value;
            int p1_ind = a[i].index, p2_ind = a[j].index;
            answer++; answer %= mod;
            while (true) {
                int f1 = p2_ind;
                p2_ind = binSearch(2*p2-p1, n);
                int f = p1;
                p1 = p2; p1_ind = f1;
                p2 = 2*p2 - f;
                if (p2_ind <= p1_ind) break;
                if (p2_ind >= n) break;
                answer++; answer %= mod;
            }
        }
    }

    cout << answer << "\n";
    return 0;
}
