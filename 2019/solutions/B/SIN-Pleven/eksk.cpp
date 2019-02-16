#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int> > conns;
int n,a,b;
bool passed[200001];

int rec(int len, int cur1, int cur2)
{
    int ret=len;
    for (int i=0; i<conns[cur1].size(); i++)
    {
        for (int j=0; j<conns[cur2].size(); j++)
        {
            if (ret >= n/2) return ret;
            if (passed[conns[cur1][i]] == false && passed[conns[cur2][j]] == false && conns[cur1][i] != conns[cur2][j])
            {
                passed[conns[cur1][i]] = true;
                passed[conns[cur2][j]] = true;
                int x = rec(len+1, conns[cur1][i], conns[cur2][j]);
                passed[conns[cur1][i]] = false;
                passed[conns[cur2][j]] = false;
                if (x > ret) ret = x;
            }
        }
    }
    return ret;
}

int main ()
{
    scanf("%d", &n);
    conns.resize(n+1);
    for (int i=0; i<n-1; i++)
    {
        scanf("%d%d", &a, &b);
        conns[a].push_back(b);
        conns[b].push_back(a);
    }
    scanf("%d%d", &a, &b);
    passed[a] = true;
    passed[b] = true;
    cout<<rec(1, a, b)<<endl;
}
/**
6
1 2
2 3
3 4
4 5
5 6
4 5

8
1 2
2 3
3 4
2 5
5 6
3 7
7 8
1 8

11
1 2
2 3
3 4
4 5
4 6
6 7
6 8
8 9
9 10
10 11
1 8
*/
