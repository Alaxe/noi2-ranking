#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 100000;

int x[MAXN];
int c[MAXN];
int u[MAXN];

int main() {

	int k; cin >> k;
	while (k--) {
		int n; cin >> n;
		for (int i = 0; i < n; ++i) {
			c[i] = 0;
			u[i] = 0;
		}
		for (int i = 0; i < n; ++i) {
			cin >> x[i];
			--x[i];
			++c[i];
			++c[x[i]];
		}
		int r = 0;
		for (int i = 0; i < n; ++i) {
			if (c[i] > r) r = c[i];
		}
		if (r == 2) {
			for (int i = 0; i < n; ++i) 
			if (!u[i]) {
				int j = i;
				int t = 1;
				while (!u[j]) {
					u[j] = t++;
					j = x[j];
				}
				if (((t - u[i]) & 1)) {
					r = 3;
					break;
				}
			}
		}
		cout << r << endl;
	}
	return 0;
}
/*
1
11
5 1 2 3 4 4 6 6 6 6 6

*/
