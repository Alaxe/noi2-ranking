#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAXN=200002;

int n;
vector <int> v[MAXN], empty_v;
vector <vector <int> > ex_a, ex_b;
int a, b, ab;

void Init ()
{
    cin>>n;
    for (int i=1; i<n; i++)
    {
        int x, y;
        cin>>x>>y;
        v[x].push_back (y);
        v[y].push_back (x);
    }
    cin>>a>>b;
}

int DFS_For_Length_AB (int u)
{
    if (u==b) return 1;
    int sz=v[u].size ();
    for (int i=0; i<sz; i++)
    {
        int p=DFS_For_Length_AB (v[u][i]);
        if (p!=0) return p+1;
    }
    return 0;
}


int main ()
{
    Init ();
    ab=DFS_For_Length_AB (a)-1;
    cout<<ab<<endl;
    return 0;
}
