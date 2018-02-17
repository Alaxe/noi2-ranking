#include <bits/stdc++.h>
using namespace std;
const int MAXN = (1 << 10);
const int MAXD = (1 << 10);
const long long mod = 123456789012345ll;

int n;
int a[MAXN];

void read()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
}

long long ans = 0, dp[MAXN][MAXD];

void solve()
{
	for(int i = 0; i < n; i++)
	{	
		for(int d = 1; d < MAXD; d++) dp[i][d] = 1; 
		for(int j = 0; j < i; j++)
			if(a[i] > a[j])
				dp[i][a[i] - a[j]] = (dp[i][a[i] - a[j]] + dp[j][a[i] - a[j]]) % mod;	

		for(int d = 1; d < MAXD; d++) ans = (ans + dp[i][d] - 1ll + mod) % mod;
	}

	printf("%lld\n", ans);
}

int main()
{
	read();
	solve();
	return 0;
}
