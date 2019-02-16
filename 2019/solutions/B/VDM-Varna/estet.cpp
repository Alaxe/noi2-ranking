#include <iostream>

using namespace std;

void input();
void solve();
const int MAXN = 100000;///100 000
int a[MAXN];
int n;

int dt[3][MAXN];

void solve() {
	///Ascending
	for(int i = 0; i < n; ++i) {
		dt[0][i] = 1;
		for(int j = i - 1; j >= 0; --j) {
			if(a[i] > a[j]) {
				if(dt[0][i] < dt[0][j] + 1) {
					dt[0][i] = dt[0][j] + 1;
				}
			}
		}
	}
	///Backwards Ascending
	for(int i = n - 1; i >= 0; --i) {
		dt[1][i] = 1;
		for(int j = i + 1; j < n; ++j) {
			if(a[i] > a[j]) {
				if(dt[1][i] < dt[1][j] + 1) {
					dt[1][i] = dt[1][j] + 1;
				}
			}
		}
	}
	///Extract Answer
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		int curr_ans = dt[0][i] + dt[1][i] - 1;
		if(curr_ans > ans) {
			ans = curr_ans;
		}
	}
	cout << ans << endl;

	///Test Output
	/*
	for(int i = 0;i < n; ++i) {
		cout << dt[0][i] << "  ";
	}
	cout << endl;
	for(int i = 0;i < n; ++i) {
		cout << dt[1][i] << "  ";
	}
	cout << endl;
	*/
}

int main() {
	input();
	solve();
	return 0;
}

void input() {
	/** Test Inputs
10
2 4 3 6 5 3 7 6 6 3

4
2 1 5 3

3
1 5 5

20
41 67 34 1 69 24 78 58 62 64 5 45 81 27 61 91 95 42 27 36

41
18467
6334
26500
19169
15724
11478
29358
26962
24464
5705
28145
23281
16827
9961
491
2995
11942
4827
5436
	**/
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 0;i < n; ++i) {
		cin >> a[i];
	}
}
