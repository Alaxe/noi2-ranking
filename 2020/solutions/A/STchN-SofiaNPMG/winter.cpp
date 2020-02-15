// O(M + N)
#include <iostream>
#include <vector>
#include <queue>
using std::cin; using std::cout; using std::endl;

// common
const int MAX_N = 1e5 + 10;
const int MAX_M = 2e5 + 10;
int nodes;
std::vector<std::pair<int, int>> graph[MAX_M];
std::vector<std::pair<int, int>> edges;

bool bridge[MAX_M];
int depth[MAX_N];
// uses dfs
int findBridges(int curr, int parent) {
	int minDepth = depth[curr];
	for(auto &fuck : graph[curr]) { // why u no [nei, edge] work? :<
		const int nei = fuck.first;
		const int edge = fuck.second;
		if(depth[nei] != -1) {
			if(parent != nei) {
				bridge[edge] = false;
				minDepth = std::min(minDepth, depth[nei]);
			}
		} else {
			depth[nei] = depth[curr] + 1;
			int D = findBridges(nei, curr);
			minDepth = std::min(minDepth, D);
			if(D <= depth[curr]) {
				bridge[edge] = false;
			}
		}
	}
	//std::cout << spam << "returning minDepth=" << minDepth << std::endl;
	return minDepth;
}

// count the number of nodes in a component (bridge edges are ignored)
// uses bfs
bool counted[MAX_N];
long long count(int startNode) {
	std::queue<int> q;
	q.push(startNode);
	long long cnt = 0;
	while(q.size()) {
		int curr = q.front();
		q.pop();
		if(counted[curr]) continue;
		counted[curr] = true;
		cnt ++;
		for(auto &fuck : graph[curr]) {
			const int nei = fuck.first;
			const int edge = fuck.second;
			if(bridge[edge]) continue; // ignore bridge
			q.push(nei);
		}
	}
	return cnt;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	// input
	int edgeCnt;
	std::cin >> nodes >> edgeCnt;
	edges.resize(edgeCnt);
	for(int i = 0;i < edgeCnt;i ++) {
		std::cin >> edges[i].first >> edges[i].second;
		graph[edges[i].first] .push_back({edges[i].second, i});
		graph[edges[i].second].push_back({edges[i].first,  i});
	}

	// find bridges
	std::fill(depth, depth + MAX_N, -1);
	std::fill(bridge, bridge + MAX_M, true);
	depth[1] = 1;
	findBridges(1, -1);

	// calc answer
	long long ans = 0;
	for(int i = 1;i <= nodes;i ++) {
		if(!counted[i]) {
			const long long cnt = count(i);
			ans += cnt * (cnt - 1) / 2;
		}
	}
	std::cout << ans << std::endl;
	
	return 0;
}
