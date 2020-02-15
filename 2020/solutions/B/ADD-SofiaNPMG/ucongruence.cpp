#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MAX_U = 62, MAX_N = 1e6 + 10;
ll bin[MAX_U][MAX_U];
int arr[MAX_N], cpy[MAX_N];
int n, u;
int seen[MAX_U], ind[MAX_U], cnt;
vector<int> ans;

ll used = 0, agentriba = 0;
vector<vector<int> > rett;
int red[MAX_U];

bool cmp(const vector<int> &a, const vector<int> &b) {
    for(int i = 0; i < cnt; i ++) {
        if(a[red[i]] != b[red[i]]) {
            return a[red[i]] < b[red[i]];
        }
    }
}

void genAll(ll nmb) {
    if(used == cnt) {
        rett.push_back(ans);
        return;
    }
    ll nxt = 0, c = 0;
    while(c < used + 1) {if(seen[nxt]) {c ++;} nxt ++;}
    nxt = ind[nxt - 1];
    for(int i = nmb + 1; i <= u; i ++) {
        ans.push_back(i);
        used ++;
        genAll(i);
        used --;
        ans.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    bin[0][0] = 1;
    for(int i = 1; i < MAX_U; i ++) {
        for(int j = 0; j <= i; j ++) {
            if(j == 0) {bin[i][j] = 1;} else {bin[i][j] = bin[i - 1][j] + bin[i - 1][j - 1];}
        }
    }
    cin >> n >> u;
    for(int i = 0; i < n; i ++) {cin >> arr[i]; seen[arr[i]] = true;}
    for(int i = 0; i < MAX_U; i ++) {if(seen[i]) {++ cnt; ind[i] = cnt;} red[i] = -1;} int r = 0;
    for(int i = 0; i < n; i ++) {
        if(seen[arr[i]]) {
            seen[arr[i]] = false;
            red[r] = ind[arr[i]] - 1;
            r ++;
        }
    }
    for(int i = 0; i < n; i ++) {seen[arr[i]] = true;}
    genAll(0);
    sort(rett.begin(), rett.end(), cmp);
    ans = rett[bin[u][cnt] / 2ll];
    for(int i = 0; i < n; i ++) {
        cout << ans[ind[arr[i]] - 1] << " ";
    }
    return 0;
}


