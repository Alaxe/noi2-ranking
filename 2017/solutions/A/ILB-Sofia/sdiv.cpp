#include <iostream>
#include <string>

#define ll long long
const int maxn = 1e4+10;
const int maxk = 1e3+10;
ll mod;

ll dp[maxk], add[maxk];

int main() {
	std::ios::sync_with_stdio(false);
	std::string in;
	std::cin >> in;
	int n = in.length();
	ll k, mod;
	std::cin >> k >> mod;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			ll ost = (10 * j + in[i] - '0') % k;
			add[ost] += dp[j];
			add[ost] %= mod;
		}

		ll ost = (in[i] - '0') % k;
		add[ost]++;
		add[ost] %= mod;

		for (int j = 0; j < k; j++)
			dp[j] += add[j], dp[j] %= mod, add[j] = 0;
	}

	std::cout << dp[0] << std::endl;
}
