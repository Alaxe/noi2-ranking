#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;

int n, mult, ans;
bool checked[5001];
vector<vector<int> > v;
queue<int> q;

int main ()
{
    int boss=0;
    scanf("%d%d", &n, &mult);
    v.resize(n+1);
    for (int i=1; i<=n; i++)
    {
        int k,a;
        scanf("%d", &k);
        if (k == 0) boss = i;
        for (int j=0; j<k; j++)
        {
            scanf("%d", &a);
            v[a].push_back(i);
        }
    }
    if (boss == 0)
    {
        int ind,mxsz=0;
        for (int i=1; i<=n; i++)
            if (v[i].size() > mxsz)
            {
                mxsz = v[i].size();
                ind = i;
            }
        q.push(ind);
        checked[ind] = true;
    }
    else
    {
        q.push(boss);
        checked[boss] = true;
    }
    int val=1, lastone = q.front();
    while (!q.empty())
    {
        int cur = q.front();
        ans+=val;
        q.pop();
        for (int i=0; i<v[cur].size(); i++)
        {
            if (checked[v[cur][i]] == false)
            {
                checked[v[cur][i]] = true;
                q.push(v[cur][i]);
            }
            if (cur == lastone && i == v[cur].size()-1)
            {
                val++;
                lastone = v[cur][i];
            }
        }
    }
    cout<<ans*mult<<endl;
}
/**
4 100
1 4
3 1 3 4
2 1 2
1 3

8 100
4 2 3 5 7
3 1 6 7
5 1 4 5 6 8
2 1 8
5 1 2 3 7 8
4 3 4 5 8
6 1 2 3 4 5 6
3 2 4 5
*/
