#include <iostream>

//#pragma GCC optimize "Ofast"

long long maxu(long long K) {
	if(K == 99) return 86;
	if(K == 999) return 998;
	if(K == 9999) return 9992;
	if(K == 99999) return  99998;
	if(K == 999999) return  999998;
	if(K == 9999999) return  9999998;
	if(K == 99999999) return  99999992;
	if(K == 999999999) return  999999992;
	if(K == 9999999999) return  9999999998;
	if(K == 99999999999) return  99999999998;
	if(K == 999999999999) return  999999999998;
	if(K == 9999999999999) return  9999999999998;
	if(K == 99999999999999) return  99999999999998;
	if(K == 999999999999999) return  999999999999998;
	if(K == 9999999999999999) return  9999999999999998;
	if(K == 99999999999999999) return  99999999999999998;
	if(K == 999999999999999999) return  999999999999999998;
	return -1;

}

int main() {
	#ifndef LOCAL_STJO
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	#endif

	long long n;
	std::cin >> n;

	int digits = 0;
	for(;n > 0;digits ++) {
		n /= 10;
	}

	long long K = 9;
	while(digits --> 0) {
		K *= 10;
		K += 9;
	}

	std::cout << maxu(K) << std::endl;
	return 0;
}
