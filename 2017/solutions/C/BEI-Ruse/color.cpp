#include<iostream>
#include<vector>

using namespace std;

const int MAXT=10;
const int MAXN=100000;
int t;
int n;
int x[MAXN+100];
int ans[MAXT+2];

int input()
{
    int temp;
    int max=0;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>temp;
        temp--;
        x[temp]++;
        x[i]++;
        if (max<x[temp]) max=x[temp];
        if (max<x[i]) max=x[i];
    }
    if (n%2==1 && max<3) max=3;
    return max;
}

void output()
{
    for (int i=0; i<t; i++)
    {
        cout<<ans[i]<<'\n';
    }
}

void nul()
{
    for (int i=0; i<n; i++)
    {
        x[i]=0;
    }
}

void solve()
{
    cin>>t;
    for (int i=0; i<t; i++)
    {
        nul();
        ans[i]=input();
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    solve();
    output();
    return 0;
}
/*
2
4
4 1 2 3
5
4 1 2 3 4

*/