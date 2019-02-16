#include <bits/stdc++.h>
using namespace std;

#define MAX 5010

int n, k, br[MAX], p, kl;
bool used[MAX];
long long ans = LLONG_MAX/10, sum, t[MAX];
vector<int> gr[MAX];
stack<int> s;
queue<int> q, res[MAX];

void BFS(int node)
{

    int op;
    fill(t, t + n + 5, k);
    fill(used, used + n + 5, false);
    s.push(node);
    q.push(node);
    while(q.size() > 0)
    {
        op = q.front();
        q.pop();
        used[op] = true;
        for(int i = 0; i < gr[op].size(); i++)
        {
            if(used[gr[op][i]] == false)
            {
                res[op].push(gr[op][i]);
                s.push(gr[op][i]);
                q.push(gr[op][i]);
                used[gr[op][i]] = true;
            }
        }
    }
    if(s.size() < n)
    {
        while(s.size() > 0)
        {
            op = s.top();
            while(res[op].size() > 0)
            {
                res[op].pop();
            }
            s.pop();
        }
        return;
    }
    while(s.size() > 0)
    {
        op = s.top();
        //cout << op << endl;
        while(res[op].size() > 0)
        {
            t[op] += t[res[op].front()];
            res[op].pop();
        }
        s.pop();
    }
    sum = 0;
    for(int i = 0 ; i < n; i++)sum += t[i];
    ans = min(ans, sum);

    return ;
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d" ,&br[i]);
        for(int j = 0; j < br[i]; j++)
        {
            scanf("%d" ,&p);
            gr[p-1].push_back(i);
        }
    }
    for(int i = 0; i < n; i++)BFS(i);
    cout << ans << endl;
    return 0;
}
/*

4 100
1 4
3 1 3 4
2 1 2
1 3

3 100
0
1 1
1 2

*/
