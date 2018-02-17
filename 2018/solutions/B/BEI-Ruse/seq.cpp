#include<iostream>

using namespace std;

const int MAXN=270;
const int MAXM=270;
int n, m;
unsigned long long st[MAXM+40][MAXM+40];

void input()
{
    cin>>n>>m;
}

void output()
{
    cout<<st[n][min(m, n)]<<endl;
}

void combinations(int c)
{
    for (int i=1; i<c; i++)
    {
        st[c][i]=st[c-i][min(i, c-i)]+st[c][i-1];
    }
    st[c][c]=st[c][c-1]+1;
}

void solve()
{
    for (int i=1; i<=n; i++)
    {
        combinations(i);
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