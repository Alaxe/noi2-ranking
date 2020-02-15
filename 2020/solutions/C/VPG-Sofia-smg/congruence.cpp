#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
string s;
bool used[32];
char let[32], small[260], big[260];
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> s;
    int n=s.size();
    int br=0;
    for (int i=0;i<n;i++) {
        if (!used[s[i]-'A']) {
            used[s[i]-'A']=true;
            let[br]=s[i];
            br++;
        }
    }
    sort(let,let+br);
    for (int i=0;i<br;i++) {
        small[let[i]]=i+'A';
        big[let[i]]='Z'-(br-i-1);
    }
    for (int i=0;i<n;i++) cout << small[s[i]];
    cout << endl;
    for (int i=0;i<n;i++) cout << big[s[i]];
    cout << endl;
    return 0;
}
/// ABCDEFGHIJKLMNOPQRSTUVWXYZ
