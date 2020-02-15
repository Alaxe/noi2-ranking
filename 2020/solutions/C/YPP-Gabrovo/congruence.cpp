#include <algorithm>
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int a[32];
bool b[32];
char s[15000005];

int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n = 0;
    for (int i = 0; cin >> s[i]; ++ i)
        n++;

    vector<int> letters;
    for (int i = 0; i < n; ++ i)
    {
        if (!b[s[i] - 'A'])
        {
            letters.push_back(s[i] - 'A');
            b[s[i] - 'A'] = true;
        }
    }

    sort(letters.begin(), letters.end());

    for (int i = 0; i < letters.size(); ++ i)
    {
        a[letters[i]] = i;
    }

    for (int i = 0; i < n; ++ i)
        cout << char(a[s[i] - 'A'] + 'A');
    cout << endl;

    int len = 26 - letters.size();
    for (int i = 0; i < n; ++ i)
        cout << char((a[s[i] - 'A'] + len) + 'A');
    cout << endl;

    return 0;
}
