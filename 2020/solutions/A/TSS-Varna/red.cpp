#include <bits/stdc++.h>
using namespace std;

vector <int> shift(vector <int> & S)
{
    vector <int> M;
    M.resize(S.size() - 1);
    for (int i = 0; i != S.size() - 1; i ++)
    {
        M[i] = S[i + 1];
    }
    return M;
}

void pr(vector <int> v)
{
    for (int elem : v)
    {
        cout<<elem<<" ";
    }
    cout<<endl;
}

set <vector <int>> keys;
map <vector <int>, pair <int, int>> M;

void get_first_equal(const vector <int> &V, int k)
{
    vector <int> s;
    int last = -1;
    int z = 0;
    for (int i = 0; i != V.size(); i ++)
    {
        if (V[i] == last)
        {
            s.push_back(V[i]);
            z ++;
            ///pr(s);
            if (z == k)
            {
                keys.insert(s);
                M[s].first ++;
                s = shift(s);
                z --;
            }
        }
        else
        {
            s = {};
            s.push_back(V[i]);
            z = 1;
            ///pr(s);
        }
        last = V[i];
    }
}

void get_first_greater(const vector <int> &V, int k)
{
    vector <int> s;
    int last = -1;
    int z = 0;
    for (int i = 0; i != V.size(); i ++)
    {
        if (V[i] > last)
        {
            s.push_back(V[i]);
            z ++;
            ///pr(s);
            if (z == k)
            {
                keys.insert(s);
                M[s].first ++;
                s = shift(s);
                z --;
            }
        }
        else
        {
            s = {};
            s.push_back(V[i]);
            z = 1;
            ///pr(s);
        }
        last = V[i];
    }
}

void get_second_equal(const vector <int> &V, int k)
{
    vector <int> s;
    int last = -1;
    int z = 0;
    for (int i = 0; i != V.size(); i ++)
    {
        if (V[i] == last)
        {
            s.push_back(V[i]);
            z ++;
            ///pr(s);
            if (z == k)
            {
                keys.insert(s);
                M[s].second ++;
                s = shift(s);
                z --;
            }
        }
        else
        {
            s = {};
            s.push_back(V[i]);
            z = 1;
            ///pr(s);
        }
        last = V[i];
    }
}

void get_second_greater(const vector <int> &V, int k)
{
    vector <int> s;
    int last = -1;
    int z = 0;
    for (int i = 0; i != V.size(); i ++)
    {
        if (V[i] > last)
        {
            s.push_back(V[i]);
            z ++;
            ///pr(s);
            if (z == k)
            {
                keys.insert(s);
                M[s].second ++;
                s = shift(s);
                z --;
            }
        }
        else
        {
            s = {};
            s.push_back(V[i]);
            z = 1;
            ///pr(s);
        }
        last = V[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long ans = 0;
    int l;
    int w, k;
    cin>>w>>k;
    int n, m;
    cin>>n;
    vector <int> a;
    for (int i = 0; i != n; i ++)
    {
        cin>>l;
        a.push_back(l);
    }
    cin>>m;
    vector <int> b;
    for (int i = 0; i != m; i ++)
    {
        cin>>l;
        b.push_back(l);
    }
    if (w == 1)
    {
        get_first_greater(a, k);
        get_second_greater(b, k);
    }
    else
    {
        get_first_equal(a, k);
        get_second_equal(b, k);
    }

    ///vector <int> a = {1, 2, 3, 4, 5, 6, 2, 3, 4, 5, 6};
    ///vector <int> b = {2, 3, 4, 5, 6};

    for (auto it = keys.begin(); it != keys.end(); it ++)
    {
        ans += M[*it].first * M[*it].second;
       /// cout<<M[*it].first<<" "<<endl;
       /// cout<<M[*it].second<<" "<<endl;
       /// pr(*it);
    }
    cout<<ans;
    return 0;
}
