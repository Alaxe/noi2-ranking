#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
char a[30];
string s, s1, s2;
int n = 0, k, t = 0;
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    s1 = "";
    s2 = "";
    cin >> s;
    n = s.size();
    s = '@' + s;

    for(int i = 0; i <= n; i ++)
    {
        a[s[i] -'A'+1] = s[i];
    }
    a[0] = 'A' - 1;

    for(int i = 1; i < 27; i ++)
    {
        if(a[i] >= 'A' && a[i] <= 'Z') a[i] = char(a[i-1] + 1), t ++;
        else a[i] = char(a[i-1]);
    }

    for(int i = 0; i < n; i ++)
    {
        s1 = s1 + a[s[i+1] - 'A' + 1];
        k = a[s[i+1] - 'A'] + 27 - t;
        s2 = s2 + char(k);
    }
    cout << s1 << endl;
    cout << s2 << endl;
    return 0;
}
