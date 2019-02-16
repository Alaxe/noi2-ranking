#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 200000;

vector<vector<int> > graph;
int verticesData[MAX_N];
int n;

struct Edge
{
    int to;
    int dist;
    Edge(int _to, int _dist)
    {
        to = _to;
        dist = _dist;
    }
};
int distances_gorno[MAX_N];
int distances_dolno[MAX_N];

int main()
{
    cin >> n;
    for(int i = 0; i < n - 1; ++ i)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    int gorno, dolno;
    cin >> gorno >> dolno;

    queue<Edge> dolnoQ;
    queue<Edge> gornoQ;

    dolnoQ.push(Edge(dolno, 0));
    gornoQ.push(Edge(gorno, 0));

    int answer = 0;
    while(!(gornoQ.empty()) && !(dolnoQ.empty()))
    {

        if(distances_dolno[dolnoQ.front().to] > answer && distances_gorno[gornoQ.front().to] > answer)
        {
            bool shouldstop = false;
            for(auto x = gornoQ.front(); x != (gornoQ.back()) && !shouldstop; x ++)
            {/// ako tva se kompilira shte raboti;
                for(auto y = dolnoQ.front(); y != (dolnoQ.back()) && !shouldstop; y ++)
                {
                    if(x.to != y.to)
                    {
                        shouldstop = true;
                    }
                }
            }
            if(shouldstop)
            {
                answer ++;
            }
            else
            {
                cout << answer;
                return 0;
            }
        }

        int currGorno = gornoQ.front();
        gornoQ.pop();
        int currDolno = dolnoQ.front();
        dolnoQ.pop();

        for(int i = 0; i < graph[currGorno].size(); i ++)
        {
            gornoQ.push(Edge(graph[currGorno][i]), distances_gorno[currGorno] + 1);
            distances_gorno[graph[currGorno][i]] = distances_gorno[currGorno] + 1;
        }
        for(int i = 0; i < graph[currDolno].size(); i ++)
        {
            dolnoQ.push(Edge(graph[currDolno][i]), distances_dolno[currDolno] + 1);
            distances_dolno[graph[currDolno][i]] = distances_dolno[currDolno] + 1;
        }
    }

}
