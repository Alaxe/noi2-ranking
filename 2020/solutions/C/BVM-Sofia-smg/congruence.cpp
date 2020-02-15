#include <bits/stdc++.h>
using namespace std;
bool here[26];
int numhigh[26];
int numlow[26];
string s;
int cnt;
int main () {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> s;
    for (int i = 0 ; i < s.size() && cnt < 26 ; ++i) {
        if (!here[s[i]-'A']) {
            here[s[i]-'A'] = 1;
            ++cnt;
        }
    }
    cnt = 0;
    for (int i = 0 ; i < 26 ; ++i) {
        if (here[i]) {
            numlow[i] = cnt;
            ++cnt;
        }
    }
    cnt = 25;
    for (int i = 25 ; i >= 0 ; --i) {
        if (here[i]) {
            numhigh[i] = cnt;
            --cnt;
        }
    }
    for (char c : s) {
        cout << char(numlow[c-'A'] + 'A');
    }
    cout << '\n';
    for (char c : s) {
        cout << char(numhigh[c-'A'] + 'A');
    }
    cout << '\n';
    return 0;
}
