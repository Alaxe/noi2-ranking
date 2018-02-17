#include <iostream>
#include <ctime>

int x[1005], y[1005];

int gcd(int a, int b) {
	if(a > b) std::swap(a, b);
	int ret = 1;
	for(int i = 2;i <= a;++ i) {
		while(a % i == 0 and b % i == 0) {
			ret *= i;
			a /= i;
			b /= i;
		}
	}
	return ret;
}

int abs(int a) {
	return (a < 0 ? -a : a);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	/*
	while(true) {
		int a, b;
		std::cin >> a >> b;
		std::cout << gcd(a, b) << std::endl;
	}
	*/
	int n;
	std::cin >> n;
	for(int i = 0;i < n;++ i) {
		std::cin >> x[i] >> y[i];
		x[i] += 100;
		y[i] += 100;
	}

	int max_ans = 0;
	if(n == 1) max_ans = 1;
	if(n == 2) max_ans = 2;

	clock_t tot = 0;
	clock_t start = clock();
	for(int a = 0;a < n;++ a) {
		for(int b = 0;b < a;++ b) {
			int cnt = 2;
			int xd = x[a] - x[b];
			int yd = y[a] - y[b];

			//clock_t sh = clock();
			const int g = gcd(abs(xd),abs(yd));
			//clock_t sh2 = clock();
			//tot += (sh2 - sh);

			xd /= g;
			yd /= g;

			if(xd == 0) {
				for(int c = 0;c < b;++ c) {
					if(x[c] == x[a]) cnt ++;
				}
			} else if(yd == 0) {
				for(int c = 0;c < b;++ c) {
					if(y[c] == y[a]) cnt ++;
				}
			} else {
				for(int c = 0;c < b;++ c) {
					const int nx = x[a] - x[c];
					const int ny = y[a] - y[c];

					if(nx % xd == 0 and ny % yd == 0 and nx / xd == ny / yd) cnt ++;
					//std::cout << a << ' ' << b << ' ' << c << std::endl;
				}
			}
			if(cnt > max_ans) max_ans = cnt;
		}
	}
	clock_t end = clock();
	//std::cout << (end-start) / double(CLOCKS_PER_SEC) << std::endl;
	//std::cout << (tot) / double(CLOCKS_PER_SEC) << std::endl;
	std::cout << max_ans << std::endl;
	return 0;
}
