#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
#define pb push_back

void bfs(vvi &graph, int source, vb &used, int &edge_cnt, int &vert_cnt)
{
    queue<int> q;
    q.push(source);
    used[source] = true;
    edge_cnt++;
    vert_cnt++;
    while(!q.empty())
    {

        int curr = q.front();
        q.pop();
        vi swamp = graph[curr];
        for(vert:swamp)
        {

            edge_cnt++;
            if(!used[vert])
            {
                vert_cnt++;
                q.push(vert);
            }
            used[vert] = true;
        }
    }
}

bool edge_check(vvi graph, int _left, int _right)
{
    int n = graph.size();
    graph = *new vvi(graph);
    vb used = *(new vb(n, false));
    for(int i=0;i<graph[_left].size();i++)
        if(graph[_left][i] == _right)
        {
            graph[_left].erase(graph[_left].begin() + i);
        }


    for(int i=0;i<graph[_right].size();i++)
        if(graph[_right][i] == _left)
        {
            graph[_right].erase(graph[_right].begin() + i);
        }

    int edges = 0, vertices = 0;
    bfs(graph, _left, used, edges, vertices);
    return used[_right];
}

int over(int n)
{
    return n*(n-1)/2;
}

int calc(vvi graph)
{
    int n = graph.size();
    int result = 0, source;
    vb used = *(new vb(n, false));
    while(used != vb(n,true))
    {
        for(int i=0;i<n;i++)
            if(!used[i])
        {
            source = i;
            break;
        }


        int edges = 0, verts = 0;
        bfs(graph, source, used, edges, verts);

        if(edges != verts - 1)
            result += over(verts);
    }
    return result;
}

vvi graph;
int n,m;

void read()
{
    cin>>n>>m;
    graph = vvi(n, vi());
    for(int i=0;i<m;i++)
    {
        int k, p;
        cin>>k>>p;
        graph[k-1].pb(p-1);
        graph[p-1].pb(k-1);
    }
}

void solve()
{
    for(int _left=0; _left<n; _left++)
        for(_right:graph[_left])
            if(!edge_check(graph,_left,_right))
            {
                for(int i=0;i<graph[_left].size();i++)
                    if(graph[_left][i] == _right)
                    {
                        graph[_left].erase(graph[_left].begin() + i);
                        break;
                    }


                for(int i=0;i<graph[_right].size();i++)
                    if(graph[_right][i] == _left)
                    {
                        graph[_right].erase(graph[_right].begin() + i);
                        break;
                    }
            }


    cout<<calc(graph)<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    read();
    solve();

    return 0;
}
/*
5 5
1 2
2 3
3 1
2 4
2 5
*/
