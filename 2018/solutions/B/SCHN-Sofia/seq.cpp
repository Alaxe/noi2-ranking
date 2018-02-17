#include <iostream>
#include <ctime>

bool calc[280][280];
long long res[280][280];

bool debug;
long long ans(int sum, int max) {
	if(debug) std::cout << "CALLED " << sum << " " << max << std::endl;
	if(calc[sum][max]) return res[sum][max];

	long long ret = 0;
	for(int c = 1;c <= sum and c <= max;++ c) {
		ret += ans(sum - c, c);
	}

	calc[sum][max] = true;
	res[sum][max] = ret;

	return ret;
}

int main() {
	for(int i = 0;i < 280;++ i) {
		calc[0][i] = true;
		res[0][i] = 1;

		calc[i][0] = true;
		res[i][0] = 0;

		calc[1][i] = true;
		res[1][i] = 1;

		calc[i][1] = true;
		res[i][1] = 1;
	}

	/*
	for(int i = -1;i < 10;++ i) std::cout << i << '\t';
	std::cout << std::endl;

	for(int i = 0;i < 30;++ i) {
		std::cout << i << ")\t";
		for(int j = 0;j < 10;++ j) {
			std::cout << ans(i, j) << '\t';
		}
		std::cout << std::endl;
	}
	debug = true;
	while(true) {
	int max, sum;
	std::cin >> sum >> max;
	std::cout << ans(sum, max) << std::endl;
	}
	*/

	/*
	clock_t a = clock();
	std::cout << ans(270, 270) << std::endl;;
	clock_t b = clock();
	std::cout << (b - a) / double(CLOCKS_PER_SEC) << std::endl;
	*/

	int max, sum;
	std::cin >> sum >> max;
	std::cout << ans(sum, max) << std::endl;
}
