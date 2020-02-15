#include <bits/stdc++.h>

#define ENDL '\n'

namespace {
	const int max_n = 2e2 + 5;

	int mem[max_n][max_n][max_n];

	int n;
	std::vector<int> items;
	int w_1, w_2;

	auto solve(int curr_w_1, int curr_w_2, int curr_idx) -> int {
		auto sol_mem = &mem[curr_w_1][curr_w_2][curr_idx];

		if(*sol_mem != -1) {
			return *sol_mem;
		}
		
		if(curr_idx >= n) {
			return *sol_mem = w_1 + w_2 - curr_w_1 - curr_w_2;
		}

		auto curr_item = items[curr_idx];
		
		auto delta_1  = curr_w_1 - curr_item;
		auto delta_2  = curr_w_2 - curr_item;
		auto next_idx = curr_idx + 1;

		auto ans_1 = delta_1 >= 0 ?
			     solve(delta_1, curr_w_2, next_idx) :
			     0;

		auto ans_2 = delta_2 >= 0 ?
			     solve(curr_w_1, delta_2, next_idx) :
			     0;

		auto ans_3 = solve(curr_w_1, curr_w_2, next_idx);

		return *sol_mem = std::max(ans_1, std::max(ans_2, ans_3));
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	memset(mem, -1, sizeof(mem));

	std::cin >> n;
	items.resize(n);

	std::cin >> w_1 >> w_2;

	for(auto& val : items) {
		std::cin >> val;
	}

	std::cout << solve(w_1, w_2, 0) << ENDL;

	return 0;
}
