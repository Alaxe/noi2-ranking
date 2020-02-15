#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

typedef set<int> si;

map<int, si> graph;
si visited;
set<si> cycles;
bool findCycle(bool firstTime, int origin, int currentNode, int parentNode)
{
    if(currentNode == origin)
    {
        cycles.insert(visited);
    }
    else
    {
        visited.insert(currentNode);
        for(auto it = graph[currentNode].begin(); it != graph[currentNode].end(); it++)
        {
            if(*it != parentNode)
            {
                findCycle(false, origin, *it, currentNode);
            }
        }
        visited.erase(currentNode);
    }
}

int solve()
{
    int count = 0;

    for(auto it = graph.begin(); it != graph.end(); it++)
    {
        visited.clear();
        findCycle(true, it -> first, it -> first, -1);
    }
    si firstSet = *cycles.begin();
    int k = firstSet.size();
    return k*(k-1)/2;
}

int main()
{
    int n, roads;
    cin >> n >> roads;

    for(int i = 0; i < roads; i++)
    {
        int a,b;
        cin >> a >> b;
        if(graph.count(a))
        {
            graph[a].insert(b);
        }
        else
        {
            si _set;
            _set.insert(b);
            if(!graph.count(a))
            {
                graph.insert(pair<int, si>(a,_set));
            }
            else
            {
                graph.insert(pair<int,si>(a,_set));
            }
        }

        if(graph.count(b))
        {
            graph[b].insert(a);
        }
        else
        {
            si _set;
            _set.insert(a);
            if(!graph.count(b))
            {
                graph.insert(pair<int, si>(b,_set));
            }
            else
            {
                graph.insert(pair<int,si>(b,_set));
            }
        }
    }

    int count = solve();
    cout<<count<<endl;
}
