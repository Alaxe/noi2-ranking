#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 3;

string s;
void read()
{
    cin >> s;
}

int prior(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;

    if (ch == '*' || ch == '/')
    return 2;

    return 0;
}

stack <int> idx;
int nxt_pos[maxn];
bool priors(int l, int r)
{
    for (int j = l; j <= r; j = nxt_pos[j])
        if (prior(s[j]) == 1)
            return true;

    return false;
}

bool is_visible[maxn];
void solve()
{
    int sz = s.size();
    for (int i = 0; i < sz; i++)
        nxt_pos[i] = i+1;

    for (int i = 0; i < sz; i++)
    {
        if (s[i] == '(')
            idx.push(i);

        else
            if (s[i] == ')')
        {
            int l = idx.top();
            int r = i;

            auto temp = priors(l, r);
            bool can = true;
            if (l > 0)
            {
                if (s[l-1] == '-' || s[l-1] == '*' || s[l-1] == '/')
                    if (temp)
                    can = false;
            }

            int pos = r + 1;
            if (pos < sz)
            {
                if (s[pos] == '*' || s[pos] == '/')
                    if (temp)
                        can = false;
            }

            if (!can)
                is_visible[l] = is_visible[r] = true;

            if (l > 0)
            nxt_pos[l-1] = r+1;

            idx.pop();
        }
    }

    for (int i = 0; i < sz; i++)
    {
        if (s[i] == '(' || s[i] == ')')
        {
            if (is_visible[i])
            cout << s[i];
        }

        else
            cout << s[i];
    }

    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    read();
    solve();
}
