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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN = 1e5;
int n;
int a[MAXN];
int pref[MAXN];

void recurse(int ind, vector<pii>& alts) {
    if (ind == 0) {
        alts.push_back({0,a[0]});
        return;
    }
    vector<pii> res;
    recurse(ind-1, res);
    for (pii alt : res) {
        if (alt.second > a[ind]) {
            alts.push_back({alt.first+alt.second-a[ind], alt.second});
        } else {
            alts.push_back({alt.first, a[ind]});
        }
    }
}

int main() {
    cin >> n;

    int x;
    int cnt = 0;
    int sum = 0;

    for (int i=0; i<n; i++) {
        cin >> a[i];
    sum += a[i];
    pref[i] = sum;
    }

    for (int i=0; i<n; i++) {
        if (i<n-1 && a[i] > a[i+1]) {
            x = i;
            cnt++;
        }
    }

    int ans = 0;

    if (cnt == 1) {
        ans = a[x]-a[x+1];
    } else {
        vector<pii> alts;
        recurse(n-1,alts);
        pii bestalt={1000000000,1000000};
        for (pii alt : alts) {
        bestalt = min(bestalt,alt);
        }
        ans = bestalt.first;
    }

    cout << ans;
}

