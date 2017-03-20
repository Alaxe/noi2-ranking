#include <iostream>

const long long MOD = 123456789012345;
const int MAXN = 1003;

bool mem[MAXN][MAXN];
long long res[MAXN][MAXN];
int arr[MAXN], count;

long long ans(int d, int idx) {
	if(mem[d][idx]) return res[d][idx];
	if(idx >= count) return 0;

	long long sol = 0;
	for(int i = idx + 1;i < count;i ++) {
		if(arr[i] - arr[idx] == d) {
			sol ++;
			sol += ans(d, i);
			sol %= MOD;
		}
	}

	mem[d][idx] = true;
	res[d][idx] = sol;
	return sol;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> count;
	for(int i = 0;i < count;i ++) std::cin >> arr[i];

	/*
	while(true) {
		int a, b;
		std::cin >> a >> b;
		std::cout << ans(a, b) << std::endl;
	}
	*/
	long long sol = 0;
	for(int d = 1;d < MAXN;d ++) {
		for(int i = 0;i < count;i ++) {
			const long long a = ans(d, i);
			sol += a;
			sol %= MOD;
			/*if(a > 0) {
				std::cout << "ans(" << d << "," << i << ")=" << a << "\n";
			}
			*/
		}
	}
	std::cout << sol << "\n";
	return 0;
}
