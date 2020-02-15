#include <bits/stdc++.h>
using namespace std;
const int MAXN = 15000010;

bool c[30];
int min_idx[30], max_idx[30];
char s[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sz = 0;
    while(cin >> s[sz ++]);
    sz --;
    for (int i = 0; i < sz; i ++)
        c[s[i] - 'A'] = true;

    int idx = 0;
    for (int i = 0; i < 27; i ++)
        if (c[i] == 1)
        min_idx[i] = idx ++;

    idx = 25;
    for (int i = 26; i >= 0; i --)
        if (c[i] == 1)
        max_idx[i] = idx --;

    for (int i = 0; i < sz; i ++)
    {
        cout << (char)(min_idx[s[i] - 'A'] + 'A');
        ///maxs[i] = (char)(max_idx[s[i] - 'A'] + 'A');
    }
    cout << endl;

    for (int i = 0; i < sz; i ++)
    {
        //cout << (char)(min_idx[s[i] - 'A'] + 'A');
        cout << (char)(max_idx[s[i] - 'A'] + 'A');
    }
    cout << endl;
    return 0;
}
