///SUBNETE ZA bili220022 V TWITCH
///profesionalen streamer i liga igrach

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1e5;
const int MAXNUM = 1e4;
int n;
int a[MAXN+10];
long long ans;

struct vector_temp
{
    int l, r;
};

void input()
{
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
    }
}

void output()
{
    cout<<ans<<endl;
}

int medianInRange(int l, int r)
{
    vector<int> s;
    while (l != r)
    {
        s.push_back(a[l]);
        l++;
    }
    s.push_back(a[l]);
    sort(s.begin(), s.end());
    return s[(s.size()-1)/2];
}

void solve()
{
    vector<vector_temp> v;
    v.push_back({0, 0});
    for (int i=1; i<n; i++)
    {
        v.push_back({i, i});

        while (v.size() > 1 &&
               medianInRange(v[v.size()-1].l, v[v.size()-1].r) <
               medianInRange(v[v.size()-2].l, v[v.size()-2].r))
        {
            v[v.size()-2].r = v[v.size()-1].r;
            v.pop_back();
        }
    }

    int curr = 0;
    ans = 0;
    for (int i=0; i<v.size(); i++)
    {
        //cerr<<v[i].l<<' '<<v[i].r<<endl;
        int temp = medianInRange(v[i].l, v[i].r);
        int new_curr = curr + (v[i].r-v[i].l+1);
        for (curr; curr<new_curr; curr++)
        {
            ans += abs(a[curr]-temp);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
    output();
    return 0;
}

/*
5
2 6 4 3 2

5
2 6 6 7 1

5
2 3 5 2 1

5
4 100 50 51 52
*/
