#include<iostream>
#include<cstring>
using namespace std;

const int maxN=200;
const int maxW=200;

int a[maxN];
int n,w1,w2;

int dp[maxN][maxW][maxW];

int W(int r1, int r2, int i)
{

	if (i == n) return 0;
	if (dp[i][r1][r2] != -1) return dp[i][r1][r2];


	int p1 = 0, p2 = 0, p = 0;

	if (r1 >= a[i])
		p1 = a[i] + W(r1 - a[i], r2, i + 1);

	if (r2 >= a[i])
		p2 = a[i] + W(r1, r2 - a[i], i + 1);

	p = W(r1, r2, i + 1);

	dp[i][r1][r2] = max(p, max(p1, p2));

	return dp[i][r1][r2];
}

int main()
{
	cin >> n >> w1 >> w2;
	for(int i=0;i<n;i++) cin >> a[i];
	memset(dp, -1, sizeof(dp));
	int r = W(w1, w2, 0);
	cout << r << endl;
}
