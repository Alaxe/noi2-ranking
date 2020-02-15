#include <iostream>
using namespace std;


int n, w1, w2;
const int MAXN = 200;
const int MAXW = 200;
int a[MAXN];
short dp[MAXN][MAXW][MAXW];
int ans;


short solve(int index, int l1, int l2) {
	if(dp[index][l1][l2] != 0)
		return dp[index][l1][l2];

	if(index < n) {
		short cmax = 0;
		int cw = a[index];
		if(l1 - cw >= 0)
			cmax = max(cmax, solve(index + 1, l1 - cw, l2));
		if(l2 - cw >= 0)
			cmax = max(cmax, solve(index + 1, l1, l2 - cw));
		cmax = max(cmax, solve(index + 1, l1, l2));
		return cmax;
	}

	return w1 + w2 - l1 - l2;
}


int main() {
	///Input
	cin >> n >> w1 >> w2;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	///Solve
	cout << solve(0, w1, w2) << endl;

	return 0;
}
