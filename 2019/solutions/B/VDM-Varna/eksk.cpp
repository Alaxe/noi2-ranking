#include <bits/stdc++.h>

using namespace std;

int n;
const int MAXN = 200001;
vector <int> nb[MAXN];
int ga, gb;
bool gusedA[MAXN];
bool gusedB[MAXN];
int max_depth;
int rec(bool usedA[MAXN], bool its_a_turn, int a, int b, int depth) {
	if(depth > max_depth && its_a_turn)
		max_depth = depth;
	if(its_a_turn) {
		bool has_run = false;
		for(int i = 0;i < nb[a].size(); ++i) {
			if(usedA[nb[a][i]] == false) {
				usedA[nb[a][i]] == true;
				has_run = true;
				rec(usedA, false, nb[a][i], b, depth + 1);
				usedA[nb[a][i]] == false;
			}
		}
		if(has_run == false) {
			return 0;
		}
	}
	else {bool has_run = false;
		for(int i = 0;i < nb[b].size(); ++i) {
			if(usedA[nb[b][i]] == false) {
				usedA[nb[b][i]] == true;
				has_run = true;
				rec(usedA, true, a, nb[b][i], depth + 1);
				usedA[nb[a][i]] == false;
			}
		}
		if(has_run == false) {
			return 0;
		}
	}
	return 0;
}

int main() {
	cin >> n;
	for(int i = 0;i < n - 1; ++i) {
		int f, t;
		cin >> f >> t;
		nb[f].push_back(t);
		nb[t].push_back(f);

	}
	cin >> ga >> gb;
	gusedA[ga] = true;
	gusedA[gb] = true;
	rec(gusedA, true, ga, gb, 0);
	cout << max_depth << endl;
	return 0;
}
/**
6
1 2
2 3
3 4
4 5
5 6
4 5

8
1 2
2 3
3 4
2 5
5 6
3 7
7 8
1 8
**/
