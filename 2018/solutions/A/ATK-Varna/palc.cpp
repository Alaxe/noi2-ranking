//Ilian first stole Denny and now Boby. Plagiarism.
#include <iostream>
#include <cstdint>
#include <string>

const uint32_t MOD = 1e9 + 7;
const uint32_t MAX_N = 1000;

uint32_t dp[MAX_N + 2][MAX_N + 2];

std::string s;
void calc_dp() {
	for (uint32_t i = 0;i < s.size();i++) {
		dp[i][i] = 1;
	}
	for (uint32_t l = 2;l <= s.size();l++) {
		//std::cout << l << "\n";
		for (uint32_t i = 0;i + l <= s.size();i++) {
			uint32_t j = i + l - 1;
			dp[i][j] = (dp[i][j - 1] + dp[i + 1][j]) % MOD;
			dp[i][j] += MOD - dp[i + 1][j - 1];
			dp[i][j] %= MOD;
			if (s[i] == s[j]) {
				dp[i][j] += dp[i + 1][j - 1] + 1;
				dp[i][j] %= MOD;
			}
			//std::cout << "(" << i << ";" << j << "): " << dp[i][j] << "\n";

		}
	}
}

int main() {
	std::cin >> s;
	calc_dp();
	std::cout << dp[0][s.size() - 1] << "\n";
}
