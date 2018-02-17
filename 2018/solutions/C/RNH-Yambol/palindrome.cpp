#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    int i, len;

    len = s.size() / 2;
    for (i = 0; i < len; i++)
    {
        if (s[i] != s[s.size() - 1 - i]) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, os, s2;
    string ans = "";

    cin >> s;
    os = s;
    s2 = s;

    int i, len, pos;
    char c;

    len = s.size() / 2;

    for (i = 0; i < len; i++)
    {
        if (s[i] != s[s.size() - 1 - i])
        {
            c = s[i];
            if (s[s.size() - 1 - i] < c)
            {
                if ((i == 0) && (s[s.size() - 1 - i] != '0')) c = s[s.size() - 1 - i];
                else c = s[s.size() - 1 - i];
            }
            s[i] = c;
            s[s.size() - 1 - i] = c;
        }
    }

    for (i = 0; i < len; i++)
    {
        if (s2[i] != s2[s2.size() - 1 - i])
        {
            c = s2[i];
            if (s2[s2.size() - 1 - i] > c)
            {
                if ((i == 0) && (s2[s2.size() - 1 - i] != '0')) c = s2[s2.size() - 1 - i];
                else c = s2[s2.size() - 1 - i];
            }
            s2[i] = c;
            s2[s2.size() - 1 - i] = c;
        }
    }

    if (s <= os)
    {
        if (s.size() % 2 != 0)
        {
            pos = s.size() / 2;
            c = s[pos];
            if (c < '9')
            {
                c++;
                s[pos] = c;
            }
            else
            {
                c = '0';
                s[pos] = c;
                for (i = pos - 1; i >= 0; i--)
                {
                    if (s[i] == '9')
                    {
                        s[i] = '0';
                        s[s.size() - 1 - i] = '0';
                    }
                    else
                    {
                        s[i]++;
                        s[s.size() - 1 - i]++;
                        break;
                    }
                }
            }
        }
        else
        {
            pos = s.size() / 2 - 1;
            if (s[pos] < '9')
            {
                s[pos]++;
                s[pos + 1]++;
            }
            else
            {
                s[pos] = '0';
                s[pos + 1] = '0';
                for (i = pos - 1; i >= 0; i--)
                {
                    if (s[i] == '9')
                    {
                        s[i] = '0';
                        s[s.size() - 1 - i] = '0';
                    }
                    else
                    {
                        s[i]++;
                        s[s.size() - 1 - i]++;
                        break;
                    }
                }
            }
        }
    }

    if (s[0] == '0')
    {
        s = "1" + s;
        if (!isPalindrome(s))
        {
            len = s.size() / 2;
            for (i = 0; i < len; i++)
            {
                if (s[i] != s[s.size() - 1 - i])
                {
                    c = s[i];
                    if (s[s.size() - 1 - i] > c)
                    {
                        if ((i == 0) && (s[s.size() - 1 - i] != '0')) c = s[s.size() - 1 - i];
                        else c = s[s.size() - 1 - i];
                    }
                    s[i] = c;
                    s[s.size() - 1 - i] = c;
                }
            }
        }
    }

    if (s > os) ans = s;
    if (ans == "") ans = s2;
    else if ((s2 > os) && (s2 < ans)) ans = s2;

    cout << ans << '\n';

    return 0;
}
