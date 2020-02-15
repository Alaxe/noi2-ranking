#include <bits/stdc++.h>

#pragma GCC optimize "-O3"

#define endl '\n'
#define trace(x) cerr << #x << " = " << x << endl

using namespace std;

int n, u;
vector<int> a;

vector<vector<int>> sequences;
vector<int> help;

void gen(int pos) {
    if (pos == n) {
        sequences.emplace_back(help);
        return;
    }

    int from = 1, to = u;
    for (int i = 0; i < pos; i++) {
        int ql, qr;
        if (a[pos] > a[i]) {
            ql = help[i] + 1;
            qr = u;
        } else if (a[pos] == a[i]) {
            ql = qr = help[i];
        } else if (a[pos] < a[i]) {
            ql = 1;
            qr = help[i] - 1;
        }

        from = max(from, ql);
        to = min(to, qr);
    }

    for (int i = from; i <= to; i++) {
        help.emplace_back(i);
        gen(pos + 1);
        help.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> u;

    a.resize(n);
    for (int &i : a) {
        cin >> i;
    }

    gen(0);

    sort(sequences.begin(), sequences.end());

    int pos = (((int)sequences.size() + 1) >> 1) - 1;
    for (int i : sequences[pos]) {
        cout << i << ' ';
    }
    cout << endl;

    return EXIT_SUCCESS;
}
