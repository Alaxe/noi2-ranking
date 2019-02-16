#include <iostream>
#include <algorithm>
#include <queue>
#include <random>

#pragma GCC optimize "Ofast"

const int MAX_N = 5e4 + 10;

int n, m;

int endof[MAX_N];

struct Chain {
	std::deque<int> verteces;
	bool dead = false;
	bool isloop = false;
	void add(int a, int b) {
		if(verteces.front() == b) {
			verteces.push_front(a);
			isloop = (a == verteces.back());
			return;
		}
		verteces.push_back(a);
		isloop = (a == verteces.back());
		return;
	}
	void consume(Chain &other, int a, int b) {
		if(verteces.front() == a) {
			if(other.verteces.front() == b) {
				while(other.verteces.size()) {
					verteces.push_front(other.verteces.front());
					other.verteces.pop_front();
				}
				return;
			}
			if(other.verteces.back() == b) {
				while(other.verteces.size()) {
					verteces.push_front(other.verteces.back());
					other.verteces.pop_back();
				}
				return;
			}
		}
		if(verteces.back() == a) {
			if(other.verteces.front() == b) {
				while(other.verteces.size()) {
					verteces.push_back(other.verteces.front());
					other.verteces.pop_front();
				}
				return;
			}
			if(other.verteces.back() == b) {
				while(other.verteces.size()) {
					verteces.push_back(other.verteces.back());
					other.verteces.pop_back();
				}
				return;
			}
		}
	}
	void print() {
		for(auto x : verteces) std::cout << x << ' ';
		std::cout << std::endl;
	}
} chains[MAX_N];

/*
int parent[MAX_N * 2];
int find(int c) {
	if(parent[c] == 0) return c;
	return parent[c] = find(parent[c]);
}
int unite(int a, int b) {
	return parent[find(a)] = find(b);
}
*/

int longerChain(int a, int b) {
	if(chains[a].verteces.size() >= chains[b].verteces.size()) return a;
	return b;
}

int other(int x, int a, int b) {
	if(x == b) return a;
	return b;
}

int GCID = 0;

// TODO
int isEnd(int a) {
	for(int i = 0;i < GCID;i ++) {
		if(chains[i].dead) continue;
		if(chains[i].verteces.front() == a) return i;
		if(chains[i].verteces.back()  == a) return i;
	}

	return -1;
}

/*
int isPartOfLoop(int a) {
	for(int i = 0;i < GCID;i ++) {
		if(chains[i].dead) continue;
		if(chains[i].isloop) {
			for(auto x : chains[i].verteces) {
				if(x == a) return i;
			}
		}
	}

	return -1;
}
*/

void addEdge(int a, int b) {
	//int enda = isEnd(a);
	//int endb = isEnd(b);
	int enda = endof[a];
	int endb = endof[b];
	//std::cout << _enda << ' ' << enda << std::endl;

	//std::cout << "====================" << std::endl;
	//std::cout << "Called add edge " << a << ' ' << b << std::endl;

	if(enda != -1 and endb != -1) {
		// form a loop
		if(enda == endb) {
			endof[a] = -1;
			endof[b] = enda;
			chains[enda].add(b, a);
			return;
		}

		const int id = longerChain(enda, endb);
		const int ot = other(id, enda, endb);

		endof[chains[id].verteces.front()] = -1;
		endof[chains[id].verteces.back()]  = -1;
		endof[chains[ot].verteces.front()] = -1;
		endof[chains[ot].verteces.back()]  = -1;

		if(id == enda) chains[id].consume(chains[ot], a, b);
		else           chains[id].consume(chains[ot], b, a);

		endof[chains[id].verteces.front()] = id;
		endof[chains[id].verteces.back()]  = id;

		chains[ot].dead = true;

		return;
	}

	if(enda != -1 and endb == -1) {
		//std::cout << "IF 2" << std::endl;

		chains[enda].add(b, a);
		endof[a] = -1;
		endof[b] = enda;
		return;
	}

	if(enda == -1 and endb == -1) {
		//std::cout << "IF 3" << std::endl;
		/*
		bool la = isPartOfLoop(enda);
		bool lb = isPartOfLoop(enda);
		if(la == -1 and lb == -1) {
			const int id = GCID ++;
			chains[id].verteces.push_front(a);
			chains[id].verteces.push_back(b);
			return;
		}

		if(la != -1 and lb == -1) {
			lb.rotate();
			addEdge(a, b);
		}

		if(la != -1 and lb != -1) {
		}
		*/

		const int id = GCID ++;
		chains[id].verteces.push_front(a);
		chains[id].verteces.push_back(b);

		endof[a] = id;
		endof[b] = id;
		return;
	}


	addEdge(b, a);
}

int main() {
	#ifndef LOCAL_STJO
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	#endif

	/*
	while(true) {
		int a; std::cin >> a;
		if(a == 0) {
			int x;
			std::cin >> x;
			std::cout << find(x) << std::endl;
		}
		if(a == 1) {
			int x, y;
			std::cin >> x >> y;
			unite(x, y);
		}
		for(int i = 1;i < 10;i ++) { std::cout << i << '.' << parent[i] << '\n'; }
		std::cout << "============" << std::endl;
	}
	*/

	std::vector<std::pair<int, int>> inp;

	std::cin >> n >> m;
	for(int i = 0;i < m;i ++) {
		int a, b;
		std::cin >> a >> b;
		inp.push_back({a, b});
	}

	std::random_device rd;
	std::mt19937 g(rd());

	for(int tr = 0;tr < 1;tr ++) {
		std::fill(std::begin(endof), std::end(endof), -1);
		std::shuffle(inp.begin(), inp.end(), g);
		for(auto e : inp) {
			addEdge(e.first, e.second);
		}

		int cnt = 0;
		for(int i = 0;i < GCID;i ++) {
			if(chains[i].dead) continue;
			cnt ++;
		}

		std::cout << cnt << '\n';
		for(int i = 0;i < GCID;i ++) {
			if(chains[i].dead) continue;
			std::cout << chains[i].verteces.size() << ' ';
			chains[i].print();
		}
	}

	return 0;
}
