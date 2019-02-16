#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

const long long MAXN = 5005;

long long n, k;
vector <int> graph[MAXN];

queue <int> q;
int depth[MAXN];

long long BFS(int x)
{
    int seen = 0;
    long long answer = 0;
    memset(depth, 0, sizeof(depth));

    q.push(x);
    depth[x] = 1;

    while(q.empty()==false)
    {
        x = q.front();q.pop();
        answer += depth[x];

        seen++;
        for(int i = 0;i<graph[x].size();i++)
        {
            if(depth[ graph[x][i] ]==0)
            {
                q.push(graph[x][i]);
                depth[ graph[x][i] ] = depth[x] + 1;
            }
        }
    }

    if(seen!=n) return 1LL*MAXN*MAXN;
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int length, x;
    long long answer = 1LL*MAXN*MAXN;

    cin >> n >> k;
    for(int i = 1;i<=n;i++)
    {
        cin >> length;
        for(int j = 0;j<length;j++)
        {
            cin >> x;
            graph[x].push_back(i);
        }
    }

    for(int i = 1;i<=n;i++)
    {
        answer = min(answer, BFS(i));
    }

    cout << answer*1LL*k << '\n';
}
