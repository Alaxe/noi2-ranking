#include <iostream>
#include <cstdint>
#include <vector>

std::vector<uint32_t> get_primes(uint32_t maxD) {
	std::vector<bool> prime(maxD, true);
	std::vector<uint32_t> ans;

	for (uint64_t i = 2;i < maxD;i++) {
		if (prime[i]) {
			ans.push_back(i);
			for (uint64_t j = i * i;j < maxD; j += i) {
				prime[j] = false;
			}
		}
		//for (uint64_t j )
	}
	return ans;
}

uint64_t gcd(uint64_t a, uint64_t b) {
	return (b == 0) ? a : gcd(b, a % b);
}

bool test_mod(uint32_t x, uint32_t maxD, uint32_t mod) {
	std::vector<uint32_t> primes = get_primes(maxD);
	//std::cerr << "mod " << mod << "\n";
	for (uint64_t p : primes) {
		uint64_t c = p * p + x;
		//std::cerr << p << "\n";
		//continue; 	 p + x;
		if (gcd(c, mod) == 1) {
			std::cerr << x << " breaks for p = " << p << ", i.e. c = " << c << "\n";
			return false;
		}
	}
	//std::cerr << "okay\n";
	return true;
}

void test_concept() {
	for (uint32_t i = 0;i < 10000;i++) {
		test_mod(i * 15 + 11, 100000, 15);
	}
}

int main() {
	uint64_t n;
	std::cin >> n;
	uint64_t ans = n - n % 30 + 26;
	if (ans < n) {
		ans += 30;
	}
	std::cout << ans << "\n";
}
