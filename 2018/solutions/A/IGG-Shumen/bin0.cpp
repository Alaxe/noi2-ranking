# include <cstdio>

using namespace std;

const int MAX_K = 62;
const int MAX_Z = 62;

long long dp[MAX_K][MAX_Z];

inline long long nu (int k, int cz)
{
	if (cz < 0)
		return 0;
	return dp[k + 1][cz];
}

long long calc (long long t, int cz)
{
	if (!t)
		return 0;

	int i, cnt = 0;
	long long ans = 0;
	
	for (i = 0; (1LL << i) <= t; i ++);
	
	
	for (i -= 2; i >= 0; i --)
	{
		ans += nu (i - 1, cz);
		
		if (t & (1LL << i))
			ans += nu (i - 1, cz - cnt - 1);
		else
			cnt ++;
	}
	
	if (cnt == cz)
		ans ++;
	
	return ans;
}

int main ()
{
	int i, j;
	
	dp[0][0] = 1;
	for (i = 1; i < MAX_K; i ++)
	{
		dp[i][0] = 1;
		for (j = 1; j < MAX_Z; j ++)
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
	}
	
	long long a, b;
	int z;
	
	scanf ("%lld %lld %d", &a, &b, &z);
	
	printf ("%lld\n", calc (b, z) - calc (a - 1, z));

	return 0;
}

