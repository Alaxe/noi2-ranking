#include <bits/stdc++.h>

const int32_t MAX_N = 1e5;
const int32_t MAX_X = 1e5;

struct Event {
	int32_t isBegin;
	int32_t x, y, nodeId;

	Event(int32_t pX = 0, int32_t pY = 0, int32_t pNodeId = 0, int32_t pIsBegin = 0)
			: x(pX), y(pY), nodeId(pNodeId), isBegin(pIsBegin) {}

	bool operator< (const Event &other) const {
		if(x != other.x) {
			return x < other.x;
		}
		else if(isBegin != other.isBegin) {
            return isBegin > other.isBegin;
		}
		else {
			return y < other.y;
		}
	}
};

class Graph {
private:
	struct Node {
		bool isVisited;
		int32_t id, dist;
		std::vector< Node* > v;
	};

public:
	int32_t cntNodes;
	Node nodes[MAX_N + 5];

	void Init(int32_t pCntNodes) {
		cntNodes = pCntNodes;

		for(int32_t i = 1; i <= cntNodes; i++) {
            nodes[i].id = i;
		}
	}

	void AddEdge(int32_t x, int32_t y) {
        nodes[y].v.push_back(&nodes[x]);
	}

	void Bfs(Node *nd) {
		nd->isVisited = true;

		std::queue< std::pair< Node*, int32_t > > q;
		q.push({ nd, 0 });

		while(!q.empty()) {
			Node *curr = q.front().first;
			int32_t dist = q.front().second;
			q.pop();

			curr->dist = dist;

			for(auto &x : curr->v) {
                if(!x->isVisited) {
					q.push({ x, dist + 1 });
					x->isVisited = true;
                }
			}
		}
	}
};

int32_t topNodes[MAX_X + 5];
Graph g;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int32_t n;
	std::cin >> n;

	std::vector< Event > events;
	for(int32_t i = 0; i < n; i++) {
		int32_t x, y, d;
		std::cin >> x >> y >> d;

		events.push_back(Event(x, y, i + 1, 1));
		events.push_back(Event(x + d, y, i + 1, 0));
	}

	std::sort(events.begin(), events.end());

	g.Init(n + 1);

	std::set< std::pair< int32_t, int32_t > > currNodes;
	currNodes.insert({ 0, n + 1 });

	int32_t last = 0;
	for(int32_t i = 0; i < events.size(); ) {
		auto top = currNodes.end();
		top--;

		for(int32_t p = last + 1; p < events[i].x; p++) {
			topNodes[p] = top->second;
		}
		last = events[i].x - 1;

		int32_t currX = events[i].x;

		int32_t j = i;
		while(j < events.size() && events[j].x == currX && events[j].isBegin) {
			top = currNodes.lower_bound({ events[j].y, 0 });
			top--;
			g.AddEdge(events[j].nodeId, top->second);
			j++;
		}

		while(i < j) {
			currNodes.insert({ events[i].y, events[i].nodeId });
			i++;
		}

		while(i < events.size() && events[i].x == currX) {
			top = currNodes.lower_bound({ events[i].y, 0 });
			top--;
			g.AddEdge(events[i].nodeId, top->second);
			currNodes.erase({ events[i].y, events[i].nodeId });
			i++;
		}
	}

	auto top = currNodes.end();
	top--;
	for(int32_t p = last + 1; p <= MAX_X; p++) {
		topNodes[p] = top->second;
	}

	g.Bfs(&g.nodes[n + 1]);

	int32_t t;
	std::cin >> t;

	for(int32_t i = 0; i < t; i++) {
		int32_t x;
		std::cin >> x;

		std::cout << g.nodes[topNodes[x]].dist << " ";
	}
	std::cout << '\n';
}
