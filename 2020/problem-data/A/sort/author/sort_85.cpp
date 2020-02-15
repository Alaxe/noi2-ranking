#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX=999999999;

vector<int> a;
int n;

int dp[10001][10001];

int run()
{
	int a1 = *min_element(a.begin(), a.end());
	int a2 = *max_element(a.begin(), a.end());
	for (int j = a1; j <= a2; j++) dp[0][j] = abs(a[0] - j);

	for (int i = 1; i < n; i++)
    {
		int m = MAX;
		for (int j = a1; j <= a2; j++)
         {
			m = min(m, dp[i - 1][j]);
			dp[i][j] = m + abs(a[i] - j);
		 }
	}

	int r = MAX;
	for (int j = a1; j <= a2; j++) r = min(r, dp[n - 1][j]);
	return r;
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
     { int v; cin >> v; a.push_back(v);}
	int r = run();
	cout << r << endl;
}
