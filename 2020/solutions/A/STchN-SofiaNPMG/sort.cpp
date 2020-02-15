// O(N * max_value), worst case given statement => 1e5 * 1e4 = 1e9

#include <iostream>

const int MAX_N = 1e5 + 2;
const int MAX_V = 1e4 + 2;
int minOpsNeeded[2][MAX_V];
int query[2][MAX_V]; // query[x][v] = min(minOpsNeeded[x][0] : minOpsNeeded[x][v])
int input[MAX_N];

inline constexpr int myabs(int a) { return (a > 0 ? a : -a); }

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	for(int i = 0;i < n;i ++) std::cin >> input[i];
	std::fill(query[0], query[0] + MAX_V, 1e9);

	// i = 0
	for(int v = 0;v < MAX_V;v ++) {
		minOpsNeeded[0][v] = myabs(input[0] - v);
		if(v > 0) query[0][v] = std::min(query[0][v-1], minOpsNeeded[0][v]);
		else      query[0][v] = minOpsNeeded[0][v];
	}
	/*
	for(int i = 0;i < 10;i ++) {
		std::cout << "i=" << i << " mon=" << minOpsNeeded[0][i] << " q=" << query[0][i] << std::endl;
	}
	*/

	// all other
	for(int i = 1;i < n;i ++) {
		std::fill(query[1], query[1] + MAX_V, 1e9);

		for(int v = 0;v < MAX_V;v ++) {
			// input[i] := v
			if(v == 0) {
				minOpsNeeded[1][v] = minOpsNeeded[0][0] + myabs(input[i] - v);
				query[1][v] = minOpsNeeded[1][v];
			} else {
				minOpsNeeded[1][v] = query[0][v] + myabs(input[i] - v);
				query[1][v] = std::min(query[1][v-1], minOpsNeeded[1][v]);
			}
		}

		// copy
		for(int j = 0;j < MAX_V;j ++) {
			minOpsNeeded[0][j] = minOpsNeeded[1][j];
			query[0][j] = query[1][j];
		}

		/*
		std::cout << "===== " << i << std::endl;
		for(int i = 0;i < 10;i ++) {
			std::cout << "i=" << i << " mon=" << minOpsNeeded[0][i] << " q=" << query[0][i] << std::endl;
		}
		*/
	}

	int ans = 1e9;
	for(int j = 0;j < MAX_V;j ++) ans = std::min(ans, minOpsNeeded[0][j]);

	std::cout << ans << std::endl;
	return 0;
}
