#include <cstdio>
#include <cstring>

typedef unsigned uint32_t;
typedef unsigned long long uint64_t;
typedef int int32_t;
typedef long long int64_t;

const uint32_t MAX_K = 10000 + 1000;
const uint32_t MAX_N = 2000;

char seq[MAX_K];
uint32_t seqLen;

uint64_t ansMod;
uint32_t divisor;

void input() {
	scanf("%s", seq);
	seqLen = strlen(seq);

	scanf("%u %llu", &divisor, &ansMod);
}

uint64_t dp[MAX_N][MAX_K];

void calc_dp() {
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (uint32_t i = 1;i <= seqLen;i++) {
		for (uint32_t j = 0;j < divisor;j++) {
			dp[i][j] += dp[i - 1][j];
			dp[i][(j * 10 + seq[i - 1] - '0') % divisor] += dp[i - 1][j];
			//printf("(%u %u) ", j, (j * 10 + seq[i - 1] - '0') % divisor)
		}
		for (uint32_t j = 0;j < divisor;j++) {
			dp[i][j] %= ansMod;
		}
	}
}

int main() {
	input();
	calc_dp();
	///Subtract 1 because the empty subsequence doesn't count
	uint64_t ans = dp[seqLen][0] - 1;
	if (dp[seqLen][0] == 0) {
		ans = ansMod - 1;
	}
	printf("%llu\n", ans);
}
