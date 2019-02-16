#include <iostream>
#include <cstdint>
#include <vector>

const uint32_t MAX_N = 2e5;

struct Vertex;

struct Edge {
	Vertex *to;
	uint32_t revInd;
	bool used;

	void use();
};

struct Vertex {
	std::vector<Edge> edges;
	uint32_t nextE;
	uint32_t ind;
	bool odd;

	Vertex(): nextE(0), odd(false) {}

	static void add_edge(Vertex *u, Vertex *v) {
		u->edges.push_back({v, 0, false});
		v->edges.push_back({u, 0, false});

		u->edges.back().revInd = v->edges.size() - 1;
		v->edges.back().revInd = u->edges.size() - 1;
	}

	void find_odd_path(std::vector<Vertex*> &ans) {
		ans.push_back(this);
		odd = false;
		while (nextE < edges.size()) {
			Edge &e = edges[nextE++];
			if (e.used) {
				continue;
			}
			e.use();
			if (e.to->odd) {
				ans.push_back(e.to);
				e.to->odd = false;
				return;
			} else {
				e.to->find_odd_path(ans);
				return;
			}
		}
	}

	void find_euler_loop(std::vector<Vertex*> &ans) {
		while (nextE < edges.size()) {
			Edge &e = edges[nextE++];
			if (e.used) {
				continue;
			}
			e.use();
			e.to->find_euler_loop(ans);
		}
		ans.push_back(this);
	}

};

void Edge::use() {
	used = true;
	to->edges[revInd].used = true;
}

std::vector<Vertex> graph;
std::vector<std::vector<Vertex*>> leads;
std::vector<std::vector<Vertex*>> paths;

void input() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	uint32_t vCnt;
	uint32_t eCnt;

	std::cin >> vCnt >> eCnt;
	graph.resize(vCnt);
	for (uint32_t i = 0;i < vCnt;i++) {
		graph[i].ind = i + 1;

	}
	for (uint32_t i = 0;i < eCnt;i++) {
		uint32_t a, b;
		std::cin >> a >> b;
		Vertex::add_edge(&graph[a - 1], &graph[b - 1]);
	}
}

void solve() {
	for (Vertex &v : graph) {
		if (v.edges.size() % 2) {
			v.odd = true;
		}
	}
	for (Vertex &v : graph) {
		if (v.odd) {
			leads.emplace_back();
			v.find_odd_path(leads.back());
		}
	}
	if (leads.empty()) {
		leads.emplace_back();
		leads.back().push_back(&graph[0]);
	}
	for (const auto &l : leads) {
		paths.emplace_back();
		//l[0]->fill_path(paths.back(), 0, l);
		for (Vertex *v : l) {
			v->find_euler_loop(paths.back());
		}
	}
}

void print_ans() {
	std::cout << paths.size() << "\n";
	for (const auto &p : paths) {
		std::cout << p.size() << " ";
		for (const Vertex *v : p) {
			std::cout << v->ind << " ";
		}
		std::cout << "\n";
	}
}

int main() {
	input();
	solve();
	print_ans();
}
/**
8 12
2 3
3 4
5 4
2 6
4 8
6 8
8 7
5 7
6 7
1 2
1 5
1 3

*/
/**
13 16
1 2
2 5
5 6
2 3
3 4
4 2
5 7
7 11
7 8
8 12
12 13
13 8
8 9
9 7
9 10
9 5
*/
/**
13 15
1 2
2 5
5 6
2 3
3 4
4 2
5 7
7 11
7 8
8 12
12 13
13 8
8 9
9 7
9 10
*/
/**
8 10
1 2
2 3
3 4
4 1
4 5
5 6
6 4
6 8
8 7
7 6
*/
