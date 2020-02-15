#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int b, e;
} mas[100001];
vector <int> v[100001];
int n, m, used[100001], meet[100001];
void dfs (int beg, int tmp1, int tmp2)
{
    used[beg]=1;
    meet[beg]++;
    for (int i=0; i<v[beg].size(); i++)
    {
        if ((beg==tmp1 && v[beg][i]==tmp2) || (beg==tmp2 && v[beg][i]==tmp1)) continue;
        else
        {
            if (!used[v[beg][i]])
            {
                dfs(v[beg][i], tmp1, tmp2);
            }
        }
    }
}
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >>n>>m;
    for (int i=0; i<m; i++)
    {
        cin >>mas[i].b>>mas[i].e;
        v[mas[i].b].push_back(mas[i].e);
        v[mas[i].e].push_back(mas[i].b);
    }
    for (int i=0; i<m; i++)
    {
        memset (used, 0, sizeof used);
        if (mas[i].b!=1 && mas[i].e!=1) dfs(1,mas[i].b,mas[i].e);
        else
        {
            if (mas[i].b==1)
            {
                if (mas[i].e!=2) dfs(2,mas[i].b,mas[i].e);
                else dfs(3,mas[i].b,mas[i].e);
            }
            if (mas[i].e==1)
            {
                if (mas[i].b!=2) dfs(2,mas[i].b,mas[i].e);
                else dfs(3,mas[i].b,mas[i].e);
            }
        }
    }
    int br=0;
    for (int i=1; i<=n; i++)
    {
        if (meet[i]==m) br++;
    }
    cout <<br*(br-1)/2<<endl;

}
