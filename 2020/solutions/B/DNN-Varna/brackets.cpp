#include <bits/stdc++.h>
#define MAXN 200003
#define endl '\n'

using namespace std;

string s;
int l;

void input()
{
    cin >> s;
    l = s.size();
}

vector <pair<int, int> > v;
bool used[MAXN];
//char prev1[MAXN];
//char next[MAXN];
int rank1[MAXN];
bool print[MAXN];
int upd[MAXN];
int upd_back[MAXN];

void solve()
{
    stack <int> pos;
    //char tmp = '@';
    int rk = 0;
    int idx = 0;
    for (int i = 0; i < l; ++i)
    {
        /*if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            tmp = s[i];*/
        upd[i] = i + 1;
        upd_back[i] = i - 1;
        if (s[i] == '(')
        {
            pos.push(i);
            //prev1[i] = tmp;
            rk++;
            idx = max(idx, rk);
        }
        else if (s[i] == ')')
        {
            rk--;
            v.push_back(make_pair(pos.top(), i));
            rank1[v.size()-1] = rk;
            pos.pop();
            //prev1[i] = tmp;

        }
    }
    //tmp = '@';

    /*for (int i = 0; i < v.size(); ++i)
        cout << v[i].first << " " << v[i].second << " " << rank1[i] << endl;*/

    int sz = v.size();

    for (int tmp = idx; tmp >= 0; --tmp)
    {
        for (int i = 0; i < sz; ++i)
            if (rank1[i] == tmp)
            {
                char prev1 = '@';
                char next1 = '@';

                //cout << "> " << v[i].first << " " << v[i].second << endl;

                /// check for prev1
                int j = upd_back[v[i].first];
                while (j >= 0)
                {
                    if (s[j] == '+' || s[j] == '-' || s[j] == '*' || s[j] == '/')
                    {
                        prev1 = s[j];
                        break;
                    }
                    else if (s[j] == '(' && !used[j])
                    {
                        prev1 = '(';
                        break;
                    }
                    j = upd_back[j];
                }

                /// check for next1
                j = upd[v[i].second];
                while (j < l)
                {
                    if (s[j] == '+' || s[j] == '-' || s[j] == '*' || s[j] == '/')
                    {
                        next1 = s[j];
                        break;
                    }
                    else if (s[j] == ')' && !used[j])
                    {
                        next1 = ')';
                        break;
                    }
                    j = upd[j];
                }

                //cout << ">> " << prev1 << " " << next1 << endl;

                /*if (v[i].first > 0)
                    prev1 = s[v[i].first-1];
                if (v[i].second < l - 1)
                    next1 = s[v[i].second+1];*/
                /// case 0:
                if (prev1 == '@' && (next1 == '*' || next1 == '/'))
                {
                    bool check = 0;
                    int j = upd[v[i].first];
                    while (j < v[i].second)
                    {
                        if (s[j] == '+' || s[j] == '-')
                        {
                            check = 1;
                            break;
                        }
                        j = upd[j];
                    }
                    if (!check)
                    {
                        print[v[i].first] = 1;
                        print[v[i].second] = 1;
                        upd[v[i].first] = v[i].second + 1;
                        upd_back[v[i].second] = v[i].first - 1;
                        used[v[i].first] = 1;
                        used[v[i].second] = 1;
                        continue;
                    }
                }

                /// case 1:
                if ((prev1 == '@' || prev1 == '(') && (next1 == ')' || next1 == '@'))
                {
                    print[v[i].first] = 1;
                    print[v[i].second] = 1;
                    upd[v[i].first] = v[i].second + 1;
                    upd_back[v[i].second] = v[i].first - 1;
                    used[v[i].first] = 1;
                    used[v[i].second] = 1;
                    continue;
                }
                /// case 2:
                if ((prev1 == '+' || prev1 == '@' || prev1 == '(') &&
                     (next1 == '+' || next1 == '-' || next1 == ')' || next1 == '@'))
                {
                    print[v[i].first] = 1;
                    print[v[i].second] = 1;
                    upd[v[i].first] = v[i].second + 1;
                    upd_back[v[i].second] = v[i].first - 1;
                    used[v[i].first] = 1;
                    used[v[i].second] = 1;
                    continue;
                }
                /// case 3:
                if ((prev1 == '*') &&
                    (next1 == '@' || next1 == '+' || next1 == '-' || next1 == '*' || next1 == '/' || next1 == ')'))
                {
                    bool check = 0;
                    int j = upd[v[i].first];
                    while (j < v[i].second)
                    {
                        if (s[j] == '+' || s[j] == '-')
                        {
                            check = 1;
                            break;
                        }
                        j = upd[j];
                    }
                    if (!check)
                    {
                        print[v[i].first] = 1;
                        print[v[i].second] = 1;
                        upd[v[i].first] = v[i].second + 1;
                        upd_back[v[i].second] = v[i].first - 1;
                        used[v[i].first] = 1;
                        used[v[i].second] = 1;
                        continue;
                    }
                }
                /// case 4:
                if ((prev1 == '-') &&
                    (next1 == '+' || next1 == '-' || next1 == '*' || next1 == '/' || next1 == '@' || next1 == ')'))
                {
                    bool check = 0;
                    int j = upd[v[i].first];
                    while (j < v[i].second)
                    {
                        if (s[j] == '+' || s[j] == '-')
                        {
                            check = 1;
                            break;
                        }
                        j = upd[j];
                    }
                    if (!check)
                    {
                        print[v[i].first] = 1;
                        print[v[i].second] = 1;
                        upd[v[i].first] = v[i].second + 1;
                        upd_back[v[i].second] = v[i].first - 1;
                        used[v[i].first] = 1;
                        used[v[i].second] = 1;
                        continue;
                    }
                }
                /// case 4.5:
                if ((prev1 == '+') &&
                    (next1 == '+' || next1 == '-' || next1 == '*' || next1 == '/' || next1 == '@' || next1 == ')'))
                {
                    bool check = 0;
                    int j = upd[v[i].first];
                    while (j < v[i].second)
                    {
                        if (s[j] == '+' || s[j] == '-')
                        {
                            check = 1;
                            break;
                        }
                        j = upd[j];
                    }
                    if (!check)
                    {
                        print[v[i].first] = 1;
                        print[v[i].second] = 1;
                        upd[v[i].first] = v[i].second + 1;
                        upd_back[v[i].second] = v[i].first - 1;
                        used[v[i].first] = 1;
                        used[v[i].second] = 1;
                        continue;
                    }
                }
                /// case 4.6:
                if ((prev1 == '(' || prev1 == '@') &&
                    (next1 == '*' || next1 == '/'))
                {
                    bool check = 0;
                    int j = upd[v[i].first];
                    while (j < v[i].second)
                    {
                        if (s[j] == '+' || s[j] == '-')
                        {
                            check = 1;
                            break;
                        }
                        j = upd[j];
                    }
                    if (!check)
                    {
                        print[v[i].first] = 1;
                        print[v[i].second] = 1;
                        upd[v[i].first] = v[i].second + 1;
                        upd_back[v[i].second] = v[i].first - 1;
                        used[v[i].first] = 1;
                        used[v[i].second] = 1;
                        continue;
                    }
                }
                /// case 5: dont remove
                upd[v[i].first] = v[i].second + 1;
                upd_back[v[i].second] = v[i].first - 1;
                used[v[i].first] = 1;
                used[v[i].second] = 1;
            }
    }

    for (int i = 0; i < l; ++i)
        if (!print[i])
            cout << s[i];
    cout << endl;
}

/**

((&+&)*&)/&

&+(&*(&-&)-(&-&))

&+((((&/&))))/&

*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solve();

    return 0;
}
