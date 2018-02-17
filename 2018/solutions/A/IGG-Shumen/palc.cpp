# include <cstdio>
# include <cstring>

using namespace std;

const int MAX_N = 128;
const int MOD = 1000000007;

int n;
char s[MAX_N];

int dp[MAX_N][MAX_N];

int calc (int l, int r)
{
	if (l == (r + 1))
		return 0;
	if (l == r)
		return 1;
		
	if (dp[l][r] != -1)
		return dp[l][r];
	
	dp[l][r] = 0;
		
	if (s[l] == s[r])
	{
		dp[l][r] += calc (l + 1, r - 1) + 1;
		if (dp[l][r] >= MOD)
			dp[l][r] -= MOD;
	}
	dp[l][r] += calc (l + 1, r);
	if (dp[l][r] >= MOD)
		dp[l][r] -= MOD;	
	dp[l][r] += calc (l, r - 1);
	if (dp[l][r] >= MOD)
		dp[l][r] -= MOD;
	
	if ((l + 1) < r)
	{
		dp[l][r] -= calc (l + 1, r - 1);
		if (dp[l][r] < 0)
			dp[l][r] += MOD;
	}
	
	///printf ("%d %d %d\n", l, r, dp[l][r]);
	
	return dp[l][r];
}

int main ()
{
	scanf ("%s", s + 1);
	n = strlen (s + 1);
	memset (dp, -1, sizeof (dp));
	
	printf ("%d\n", calc (1, n));
	
	return 0;
}

