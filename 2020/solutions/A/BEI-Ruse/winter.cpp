///02 4life<3
#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 1e5;
int n, m;
vector<int> con[MAXN+100];
bool used[MAXN+100];
int par[MAXN+100];
int ch[MAXN+100];
long long counter;

void input()
{
    int a, b;
    cin>>n>>m;
    for (int i=0; i<m; i++)
    {
        cin>>a>>b;
        con[a-1].push_back(b-1);
        con[b-1].push_back(a-1);
    }
}

void output()
{
    cout<<counter<<endl;
}

int findPar(int curr)
{
    if (par[curr] != curr)
    {
        par[curr] = findPar(par[curr]);
        ch[par[curr]] += ch[curr];
        ch[curr] = 0;
    }
    return par[curr];
}

void unite(int a, int b)
{
    int pa = findPar(a);
    int pb = findPar(b);
    if (pa != pb)
    {
        ch[pb] += ch[pa];
        ch[pa] = 0;
        par[pb] = par[pa];
    }

}

void dfs(int curr, int last, vector<int> &v)
{
    //cerr<<curr<<endl;
    used[curr] = 1;

    for (int i=0; i<con[curr].size(); i++)
    {
        if (con[curr][i] == last) continue;
        if (!used[con[curr][i]])
        {
            v.push_back(con[curr][i]);
            dfs(con[curr][i], curr, v);
            if (v.back() == con[curr][i]) v.pop_back();
        }
        else
        {
            int tempp = findPar(con[curr][i]);
            //cerr<<curr<<' '<<con[curr][i]<<' '<<tempp<<endl;
            while(v.back() != tempp && !v.empty())
            {
                unite(tempp, v.back());
                v.pop_back();
            }
        }
    }
}

void preSet()
{
    for (int i=0; i<n; i++)
    {
        par[i] = i;
        ch[i] = 1;
    }
}

void solve()
{
    preSet();
    vector<int> v;
    v.push_back(0);
    dfs(0, 0, v);
    /*cerr<<"unions:\n";
    for (int i=0; i<n; i++)
    {
        cerr<<findPar(i)<<' ';
    }
    cerr<<"\nchildred:\n";
    for (int i=0; i<n; i++)
    {
        cerr<<ch[i]<<' ';
    }cerr<<'\n';*/

    for (int i=0; i<n; i++)
    {
        findPar(i);
    }
    for (int i=0; i<n; i++)
    {
        counter += (long long)ch[i]*(ch[i]-1)/2;
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
5 5
1 2
2 3
3 1
2 4
2 5

6 7
1 2
2 3
1 3
3 4
4 5
5 6
4 6

9 11
1 2
2 3
1 3
3 4
4 5
5 6
4 6
5 7
5 9
7 8
8 9

10 13
3 2
2 1
2 6
2 8
1 4
1 6
6 7
6 5
4 5
8 7
7 10
10 9
9 5

14 16
1 3
1 6
1 7
1 8
2 3
2 6
3 4
4 5
6 10
7 9
8 9
10 11
11 12
12 13
12 14
13 14

10 13
1 2
1 3
1 4
2 3
4 6
4 9
5 7
5 8
7 9
8 9
10 2
10 3
8 10
*/

