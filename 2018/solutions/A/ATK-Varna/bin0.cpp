#include <iostream>
#include <cstdint>

const uint32_t MAX_N = 70;

uint64_t comb[MAX_N ][MAX_N];
void calc_pascal() {
	for (uint32_t i = 0;i < MAX_N;i++) {
		comb[i][0] = 1;
		for (uint32_t j = 1;j <= i;j++) {
			comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
		}
	}
}

uint64_t leq_zero(uint64_t a, uint32_t zeroes) {
	if (a == 0) {
		return 0;
	}
	uint32_t bitCnt = 1;
	uint64_t ans = 0;
	while((1ULL << bitCnt) <= a) {
		ans += comb[bitCnt - 1][zeroes];
		bitCnt++;
	}
	//bitCnt++;
	//std::cerr << "bit " << bitCnt << " " << ans << " ";
	uint32_t curZero = 0;
	for(uint32_t i = bitCnt - 1;i > 0;i--) {
		uint32_t cBit = (a >> (i - 1)) & 1;
		//std::cerr << cBit;
		if (cBit) {
			if (zeroes >= curZero + 1) {
				ans += comb[i - 1][zeroes - curZero - 1];
			}
		} else {
			curZero++;
			if (curZero > zeroes) {
				break;
			}
		}

	}
	ans += comb[0][zeroes - curZero];
	//std::cerr << " " << ans << "\n";
	return ans;
}

int main() {
	calc_pascal();
	uint64_t l, h;
	uint32_t targ;
	std::cin >> l >> h >> targ;
	std::cout << leq_zero(h, targ) - leq_zero(l - 1, targ) << "\n";
}

//Med is the sweetest I've ever seen.
