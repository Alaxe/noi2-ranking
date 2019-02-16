
#include<iostream> 
#include <list> 

using namespace std;

 
class Graph
{
	int V; 
	list<int> *adj; 

	void printAllPathsUtil(int, int, bool[], int[], int &);

public:
	Graph(int V); 
	void addEdge(int u, int v);
	void printAllPaths(int s, int d);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v); 
}

void Graph::printAllPaths(int s, int d)
{
	
	bool *visited = new bool[V];

	
	int *path = new int[V];
	int path_index = 0; 

	
	for (int i = 0; i < V; i++)
		visited[i] = false;

	printAllPathsUtil(s, d, visited, path, path_index);
}

void Graph::printAllPathsUtil(int u, int d, bool visited[],
	int path[], int &path_index)
{
	visited[u] = true;
	path[path_index] = u;
	path_index++;

	
	if (u == d)
	{
		for (int i = 0; i < path_index; i++)
			cout << path[i] << " ";
		cout << endl;

	}
	else 
	{
		list<int>::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
			if (!visited[*i])
				printAllPathsUtil(*i, d, visited, path, path_index);
	}

	path_index--;
	visited[u] = false;
}

int main()
{
	Graph g(9);


	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(5, 4);
	g.addEdge(2, 6);
	g.addEdge(4, 8);
	g.addEdge(6, 8);
	g.addEdge(8, 7);
	g.addEdge(5, 7);
	g.addEdge(6, 7);
	g.addEdge(1, 2);
	g.addEdge(1, 5);
	g.addEdge(1, 3);

	int s = 1, d = 7;
	
	g.printAllPaths(s, d);

	return 0;
}
