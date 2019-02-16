#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

const int MAXN = 2e5 + 5;

int n;
int u, v;
vector <int> graph[MAXN];

int sparse[20][MAXN];
int depth[MAXN], maxDown[MAXN], parent[MAXN];

bool used[MAXN];
int below1, below2;
vector <int> way[2];

void DFSInit(int x, int last, int level)
{
    depth[x] = level;
    parent[x] = last;

    maxDown[x] = 1;
    for(int i = 0;i<graph[x].size();i++)
    {
        if(graph[x][i]!=last)
        {
            DFSInit(graph[x][i], x, level+1);
            maxDown[x] = max(maxDown[x], maxDown[ graph[x][i] ] + 1);
        }
    }
}

void Init(int A, int B)
{
    DFSInit(1, -1, 1);

    for(int i = 1;i<=n;i++)
    {
        sparse[0][i] = parent[i];
    }
    for(int i = 1;i<20;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            if(sparse[i-1][j]==-1)
            {
                sparse[i][j] = -1;
            }
            else
            {
                sparse[i][j] = sparse[i-1][ sparse[i-1][j] ];
            }
        }
    }

    int x = A;
    while(x!=-1)
    {
        way[0].push_back(x);
        x = parent[x];
    }

    x = B;
    while(x!=-1)
    {
        way[1].push_back(x);
        x = parent[x];
    }
}

int getLCA(int u, int v)
{
    if(depth[u]>depth[v]) swap(u, v);

    for(int i = 19;i>=0;i--)
    {
        if(sparse[i][v]==-1) continue;
        if(depth[ sparse[i][v] ]>=depth[u])
        {
            v = sparse[i][v];
        }
    }

    if(u==v) return u;
    for(int i = 19;i>=0;i--)
    {
        if(sparse[i][u]!=sparse[i][v])
        {
            u = sparse[i][u];
            v = sparse[i][v];
        }
    }

    return parent[u];
}

int getBelow(int x, int LCA)
{
    int answer = 1, way = 1;

    int last = -1;
    while(x!=LCA)
    {
        for(int i = 0;i<graph[x].size();i++)
        {
            if(graph[x][i]!=parent[x] && graph[x][i]!=last)
            {
                answer = max(answer, way + maxDown[ graph[x][i] ]);
            }
        }

        way++;
        last = x;
        x = parent[x];
    }

    return answer;
}

void markRoute(int u, int v)
{
    int LCA = getLCA(u, v);
    while(u!=LCA)
    {
        used[u] = true;
        u = parent[u];
    }
    while(v!=LCA)
    {
        used[v] = true;
        v = parent[v];
    }
}

bool check(int length, int A, int B, int LCA)
{
    //if(LCA==A || LCA==B) return false;

    if(depth[A] - depth[LCA] + 1 >= length)
    {
        //cout << "instant" << '\n';
        if(A>B)
        {
            if(below1>=length) return true;
        }
        else
        {
            if(below2>=length) return true;
        }
    }

    memset(used, false, sizeof(used));

    int headStart, vertex = -1;
    int index = ((A<B)?0:1);

    //cout << A << " " << B << " " << index << '\n';
    for(int i = way[index].size()-1;i>=0;i--)
    {
        //cout << "try " << way[index][i] << " " << depth[A] - depth[ way[index][i] ] + 1 << '\n';

        headStart = depth[A] - depth[ way[index][i] ] + 1;
        if(headStart>=length)
        {
            vertex = way[index][i];
            break;
        }

        for(int j = 0;j<graph[ way[index][i] ].size();j++)
        {
            if(i!=0 && way[index][i-1]==graph[ way[index][i] ][j])
            {
                continue;
            }
            if(i!=way[index].size()-1
                || graph[ way[index][i] ][j]==parent[ way[index][i] ])
            {
                continue;
            }

            //cout << graph[ way[index][i] ][j] << " " << maxDown[ graph[ way[index][i] ][j] ] << '\n';

            if(headStart + maxDown[ graph[ way[index][i] ][j] ] >= length)
            {
                //cout << "oke" << '\n';

                vertex = way[index][i];
                break;
            }
        }

        if(vertex!=-1) break;
    }
    if(vertex==-1)
    {
        for(int i = way[index].size()-1;i>=0;i--)
        {
            //cout << "try " << way[index][i] << " " << depth[A] - depth[ way[index][i] ] + 1 << '\n';

            headStart = depth[A] - depth[ way[index][i] ] + 1;
            for(int j = 0;j<graph[ way[index][i] ].size();j++)
            {
                if(i!=0 && way[index][i-1]==graph[ way[index][i] ][j])
                {
                    continue;
                }
                if(i!=way[index].size()-1
                    || graph[ way[index][i] ][j]==parent[ way[index][i] ])
                {
                    continue;
                }

                //cout << graph[ way[index][i] ][j] << " " << maxDown[ graph[ way[index][i] ][j] ] << '\n';

                if(headStart + maxDown[ graph[ way[index][i] ][j] ] >= length)
                {
                    //cout << "oke" << '\n';

                    vertex = way[index][i];
                    break;
                }
            }

            if(vertex!=-1) break;
        }
    }
    if(vertex==-1)
    {
        if(maxDown[A] >= length)
        {
            vertex = A;
        }
    }
    if(vertex==-1) return false;

    //cout << vertex << '\n';

    markRoute(A, vertex);
    headStart= depth[A] - depth[vertex];

    while(headStart<length)
    {
        //cout << "mark" << vertex << '\n';

        headStart++;
        used[vertex] = true;
        if(headStart>=length) break;

        int newVertex = -1;
        for(int i = 0;i<graph[vertex].size();i++)
        {
            if(getLCA(B, graph[vertex][i])==graph[vertex][i]) continue;
            if(graph[vertex][i]==parent[vertex]) continue;

            //cout << "   " << graph[vertex][i] << '\n';
            //cout << headStart << " + " << maxDown[ graph[vertex][i] ] << '\n';

            if(headStart + maxDown[ graph[vertex][i] ] >= length)
            {

                newVertex = graph[vertex][i];
                break;
            }
        }

        if(newVertex==-1)
        {
            //cout << "fak" << '\n';
            for(int i = 0;i<graph[vertex].size();i++)
            {
                if(graph[vertex][i]==parent[vertex]) continue;

                if(headStart + maxDown[ graph[vertex][i] ] >= length)
                {
                    newVertex = graph[vertex][i];
                    break;
                }
            }
        }

        if(newVertex==-1)
        {
            return false;
        }
        vertex = newVertex;
    }

    int last = -1;
    vertex = B;
    headStart = 0;
    while(vertex!=-1)
    {
        //cout << "cehck " << vertex << '\n';
        if(used[vertex]==true)
        {
            return false;
        }

        headStart++;
        if(headStart>=length) return true;

        for(int i = 0;i<graph[vertex].size();i++)
        {
            if(graph[vertex][i]==last) continue;
            if(graph[vertex][i]==parent[vertex]) continue;

            if(used[ graph[vertex][i] ]==false && headStart + maxDown[ graph[vertex][i] ] >= length)
            {
                //cout << "   " << graph[vertex][i] << '\n';
                return true;
            }
        }

        last = vertex;
        vertex = parent[vertex];
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int l, r, mid;
    int A, B, LCA;

    cin >> n;
    for(int i = 0;i<n-1;i++)
    {
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cin >> A >> B;
    if(A>B) swap(A, B);

    Init(A, B);
    LCA = getLCA(A, B);

    below1 = getBelow(A, LCA);
    below2 = getBelow(B, LCA);

    l = 1;
    r = n;
    while(l+1<r)
    {
        mid = (l+r)/2;

        if(min(below1, below2)>=mid || check(mid, A, B, LCA)==true || check(mid, B, A, LCA)==true)
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }

    if(min(below1, below2)>=r || check(r, A, B, LCA)==true || check(r, B, A, LCA)==true)
    {
        cout << r << '\n';
    }
    else if(min(below1, below2)>=l || check(l, A, B, LCA)==true || check(l, B, A, LCA)==true)
    {
        cout << l << '\n';
    }
    else
    {
        cout << "1" << '\n';
    }
}
/*
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
*/
