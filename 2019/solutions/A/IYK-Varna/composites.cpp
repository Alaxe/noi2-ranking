#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int64_t n;
	std::cin >> n;

	for(int64_t i = n; ; i++) {
        if(i % 5 == 1 && i % 3 == 2) {
			std::cout << i << '\n';
			return 0;
        }
	}
}
