#include<bits/stdc++.h>

using namespace std;

int main()
{
    bool ok = 1;
    string s;
    int edn = 0;

    cin >> s;

    for (int i = s.size() - 1; i >= s.size() / 2; i --)
    {
        if (s[i] <= s[s.size() - 1 - i])
        {
            if (s[i] == s[s.size() - 1 - i])
                edn ++;

            s[i] = s[s.size() - 1 - i];
        }
        else
            ok = 0;
    }

    if (edn == s.size() / 2 + s.size() % 2)
        ok = 0;

    if (ok)
    {
        cout << s << endl;

        return 0;
    }

    int n = s.size() / 2;

    if (!(s.size() & 1))
        n --;

    if (s[n] == '9')
    {
        s[n] = '0';
        int j = n - 1;

        while (s[j] == '9')
        {
            s[j] = '0';
            j --;

            if (j < 0)
                break;
        }

        if (j < 0)
            s = "1" + s;
        else
            s[j] ++;
    }
    else
    {
        s[n] ++;
    }

    n = s.size() / 2;

    if (!(s.size() & 1))
        n --;

    for (int i = 0; i <= n; i ++)
    {
        s[s.size() - 1 - i] = s[i];
    }

    cout << s << endl;

    return 0;
}
