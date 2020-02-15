#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int SIZE = 100001;

int n;
int m;
int cnt[SIZE];
int pr[SIZE];
int a, b;
int ans;
int i, j;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++ i) {
        cin >> a;
        ++ cnt[a];
    }
    for (int i = 1; i < SIZE; ++ i) {
        pr[i] = pr[i - 1] + cnt[i];
    }
    cin >> m;
    for (int q = 0; q < m; ++ q) {
        cin >> a >> b;
        cout << pr[b] - pr[a - 1] << endl;
    }
    return 0;
}
