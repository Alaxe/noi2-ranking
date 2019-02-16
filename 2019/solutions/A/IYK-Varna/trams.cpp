#include <bits/stdc++.h>

const int32_t MAX_N = 50000;
const int32_t MAX_M = 100000;
const int32_t MAX_K = 100000;

int32_t ansCnt;
std::vector< int32_t > ans[MAX_K + 5];

class Graph {
private:
	struct Node {
		bool isVisited;
		int32_t id, degree;
		std::vector< int32_t > v;
	};

	struct Edge {
		bool isRemoved, isVisited;
        Node *u, *v;

        Edge(Node *pU = nullptr, Node *pV = nullptr) : u(pU), v(pV) {
			isRemoved = false;
			isVisited = false;
        }

        Node* Get(Node *x) {
			if(x == u) {
				return v;
			}
			else {
				return u;
			}
        }
	};

public:
	int32_t cntNodes, cntEdges;
	Node nodes[MAX_N + 5];
	Edge edges[MAX_M + 5];

	void Init(int32_t pCntNodes) {
		cntNodes = pCntNodes;
		cntEdges = 0;

		for(int32_t i = 1; i <= cntNodes; i++) {
			nodes[i].id = i;
		}
	}

	void AddEdge(Node *x, Node *y) {
		edges[cntEdges] = Edge(x, y);
		x->v.push_back(cntEdges);
		y->v.push_back(cntEdges);
		x->degree++;
		y->degree++;
		cntEdges++;
	}

	void MarkUnvisited() {
		for(int32_t i = 1; i <= cntNodes; i++) {
			nodes[i].isVisited = false;
		}
	}

	void DfsRemoveEdges(Node *nd, int32_t d) {
		nd->isVisited = true;
		ans[ansCnt].push_back(nd->id);

		if(d != 0 && nd->degree % 2 == 0) {
			return;
		}

		for(auto &x : nd->v) {
			if(edges[x].isRemoved) {
				continue;
			}

			Node *to = edges[x].Get(nd);
			if(!to->isVisited) {
                nd->degree--;
                to->degree--;
                edges[x].isRemoved = true;
                DfsRemoveEdges(to, d + 1);
                break;
			}
		}
	}

	void RemoveEdges() {
		int32_t cntWithOdd = 0;
		for(int32_t i = 1; i <= cntNodes; i++) {
			if(nodes[i].degree % 2 != 0) {
				cntWithOdd++;
			}
		}

		for(int32_t i = 1; i <= cntNodes; i++) {
			if(cntWithOdd == 0 || cntWithOdd == 2) {
				break;
			}

			if(nodes[i].degree % 2 != 0) {
				MarkUnvisited();
				DfsRemoveEdges(&nodes[i], 0);
				cntWithOdd -= 2;
				ansCnt++;
			}
		}
	}

	void DfsEulerPath(Node *nd, std::stack< Node* > &st) {
		st.push(nd);

		for(auto &x : nd->v) {
			if(!edges[x].isVisited && !edges[x].isRemoved) {
				edges[x].isVisited = true;
                DfsEulerPath(edges[x].Get(nd), st);
			}
		}
	}

	void ComputeEulerPath() {
		Node *startNode = &nodes[1];
		for(int32_t i = 1; i <= cntNodes; i++) {
			if(nodes[i].degree % 2 != 0) {
				startNode = &nodes[i];
			}
		}

		std::stack< Node* > st;
		DfsEulerPath(startNode, st);

		while(!st.empty()) {
			Node *x = st.top();

			int32_t siz = st.size();

            st.pop();
			DfsEulerPath(x, st);

			if(st.size() == siz) {
				ans[ansCnt].push_back(x->id);
				st.pop();
			}
		}

		ansCnt++;
	}
};

Graph g;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int32_t n, m;
	std::cin >> n >> m;

	g.Init(n);
	for(int32_t i = 0; i < m; i++) {
		int32_t x, y;
		std::cin >> x >> y;

		g.AddEdge(&g.nodes[x], &g.nodes[y]);
	}

	g.RemoveEdges();
	g.ComputeEulerPath();

	std::cout << ansCnt << '\n';
	for(int32_t i = 0; i < ansCnt; i++) {
		std::cout << ans[i].size();
		for(auto &x : ans[i]) {
			std::cout << " " << x;
		}
		std::cout << '\n';
	}
}
