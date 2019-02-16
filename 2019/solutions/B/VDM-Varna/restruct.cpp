///This was supposed to be the easier solution
///FFS this has gotten so convoluted because of C++, srsly
///I've no idea, but that solution seems greedy and works kinda like Dijkstra

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void input();
void solve();
bool cmp();

const int MAXN = 5500;
int n;
int k;
int g_pos;
vector<int> wtbcot[MAXN];///What to be children of this
vector<int> children[MAXN];///Actual Children
vector<int> curr_row;
vector<int> next_row;
int checked[MAXN];
int num_used;
bool used[MAXN];
vector<int> aa[MAXN];
int ans;
int salary[MAXN];
bool cmp(int a, int b) {
	if(wtbcot[b].size() > wtbcot[a].size()) {
		return true;
	}
	return false;
}

int rec(int index) {
	//cout << 42 << endl;
	salary[index] = 1;
	for(int i = 0;i < children[index].size(); ++i) {
		salary[index] += rec(children[index][i]);
	}
	ans += salary[index];
	return salary[index];
}

void solve() {
	while (true) {
	int mx_pos = 0;
	for(int i = 1;i <= n; ++i) {
		if(!used[i] && !checked[i])
		if(wtbcot[mx_pos].size() < wtbcot[i].size()) {
			mx_pos = i;
		}
	}
	next_row.push_back(mx_pos);
	used[mx_pos] = true;
	num_used++;
	//cout << mx_pos << endl;
	while(!next_row.empty()) {
		curr_row = next_row;
		next_row.clear();
		while(!curr_row.empty()) {
			int curr = 0;
			for(int j = 0; j < curr_row.size(); ++j) {
				if(curr_row[j] > curr_row[curr]) {
					curr = j;
				}
			}
			int _curr = curr_row[curr];
			curr_row.erase(curr_row.begin() + curr);
			curr = _curr;
			for(int j = 0;j < wtbcot[curr].size(); ++j) {
				if(!used[wtbcot[curr][j]]) {

					children[curr].push_back(wtbcot[curr][j]);
					next_row.push_back(wtbcot[curr][j]);
					used[wtbcot[curr][j]] = true;
					num_used++;
				}
			}
		}
		//sort(next_row.begin(), next_row.end(), cmp());
	}
	if(num_used == n) {
		g_pos = mx_pos;
		break;
	}
	else {
		num_used--;
		used[mx_pos] = false;
		checked[mx_pos] = true;
		for(int i = 0;i < aa[mx_pos].size(); ++i) {
				bool to_brk = false;
			for(int j = 0;j < children[mx_pos].size() && !to_brk; ++j) {
				if(children[mx_pos][j] == aa[mx_pos][i]) {
					children[mx_pos].erase(children[mx_pos].begin() + j);
					to_brk = true;
				}
			}
			if(used[aa[mx_pos][i]] == true)
				num_used--;
			used[aa[mx_pos][i]] = false;
		}
	}
	}
	///Extract Answer
	rec(g_pos);
	cout << ans * k << endl;
	/*for(int i = 1;i <= n; ++i) {
		cout << salary[i] << endl;
	}
	for(int i = 1;i <= n; ++i) {
		cout << i << " ";
		for(int j = 0;j < children[i].size(); ++j) {
			cout << children[i][j] << " ";
		}
		cout << endl;
	}*/
}

int main() {
	input();
	solve();
	return 0;
}

void input() {
	/** Test Inputs
4 100
1 4
3 1 3 4
2 1 2
1 3

10 100
0
1 1
1 1
1 2
1 2
1 4
1 4
1 4
1 5
1 9

10 100
0
1 1
1 1
1 6
1 2
2 4 2
1 4
1 4
1 5
1 9
	**/
	cin >> n >> k;
	for(int i = 1;i <= n; ++i) {
		int m;
		cin >> m;
		for(int j = 0;j < m; ++j) {
			int cc;
			cin >> cc;
			wtbcot[cc].push_back(i);
			aa[i].push_back(cc);
		}
	}
	/*
	for(int i = 1; i <= n; ++i) {
		cout << i << " ";
		for(int j = 0;j < wtbcot[i].size(); ++j) {
			cout << wtbcot[i][j] << " ";
		}
		cout << endl;
	}*/
}
