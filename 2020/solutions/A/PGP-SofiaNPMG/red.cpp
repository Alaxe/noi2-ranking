#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <limits>
using namespace std;

typedef long long ll;
typedef long long unsigned llu;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN = 1e5;
const int MAXK = 1e4;

int w, k, n, m;
int A[MAXN];
int B[MAXN];

namespace type1 {
    map<llu,int> subseq;
    const int base = 2e6+3;
    llu pows[MAXK];

    void solve() {
        pows[0] = 1;
        for (int p=1; p<MAXK; p++) {
            pows[p] = pows[p-1]*base;
        }

        llu h = 0;
        int len = 0;

        for (int i=0; i<n; i++) {
            if (len == k) {
                //printf("at %d %llu-%llu=%llu from hash\n", i, h, A[i-k]*pows[k-1], h-A[i-k+1]*pows[k-1]);
                h -= A[i-k+1]*pows[k-1];
                len--;
            }
            h *= base;
            h += A[i];
            len++;

            if (len == k) {
                subseq[h]++;
            }

            if (i == n-1 || A[i] >= A[i+1]) {
                len = 0;
                h = 0;
            }
        }

        ll ans = 0;
        h = 0;
        len = 0;

        for (int i=0; i<m; i++) {
            if (len == k) {
                //printf("at %d %llu-%llu=%llu from hash\n", i, h, A[i-k+1]*pows[k-1], h-A[i-k+1]*pows[k-1]);
                h -= B[i-k]*pows[k-1];
                len--;
            }
            h *= base;
            h += B[i];
            len++;

            if (len == k) {
                ans += subseq[h];
            }

            if (i == m-1 || B[i] >= B[i+1]) {
                len = 0;
                h = 0;
            }
        }

        cout << ans;
    }
};

namespace type2 {
    map<int,int> subseq;

    void solve() {
        int st = 0;

        for (int i=0; i<n; i++)
            if (i == n-1 || A[i] != A[i+1]) {
                if (i-st+1 >= k) {
                    subseq[A[i]] += i-st+1-k+1;
                }
                st = i+1;
            }

        ll ans = 0;
        st = 0;

        for (int i=0; i<m; i++)
            if (i == m-1 || B[i] != B[i+1]) {
                if (i-st+1 >= k && subseq[B[i]]) {
                    ll x = subseq[B[i]];
                    ll y = i-st+1-k+1;
                    ans += x*y;
                }
                st = i+1;
            }

        cout << ans;
    }
}

int main() {
    cin >> w >> k;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> A[i];
    }
    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> B[i];
    }

    if (w == 1) {
        type1::solve();
    } else {
        type2::solve();
    }
}


