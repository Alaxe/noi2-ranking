#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool isThere[27];
int place[27];
int ind;

char ch;
string s;

int main() {
    while (cin >> ch) {
        s += ch;
        isThere[ch - 'A'] = true;
    }
    for (int i = 0; i < 26; ++ i) {
        if (isThere[i]) {
            place[i] = ind ++;
        }
    }
    for (size_t i = 0; i < s.size(); ++ i) {
        cout << char('A' + place[int(s[i] - 'A')]);
    }
    cout << endl;
    for (size_t i = 0; i < s.size(); ++ i) {
        cout << char('Z' - (ind - place[int(s[i] - 'A')]) + 1);
    }
    cout << endl;
    return 0;
}
