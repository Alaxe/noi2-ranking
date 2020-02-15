#include <iostream>

using namespace std;

int n, u;
const int MAXN = 1000000;///1 000 000
const int MAXU = 60;
int a[MAXN];
int smallest_set[MAXN];
int lex_set[MAXN];
bool used[MAXN];
int rmd[MAXN];
bool used1[MAXU];

int ans = 0;

void solve() {

}

void remove_doubles() {
	int j = 0;
	for(int i = 0; i < n; ++i) {
		if(!used1[smallest_set[i]]) {
			used1[smallest_set[i]] = true;
			rmd[j] = smallest_set[i];
			++j;
		}
	}
	/*for(int i = 0; i < j; ++i) {
		cout << rmd[i];
	}
	cout << endl;*/
}

void find_lex_set() {
	int base = smallest_set[0];
	for(int i = 0; i < n; ++i)
		lex_set[i] = smallest_set[i] - base;
}

void find_smallest_set() {
    int clvl = 1;
    while(true) {
		int smallest_num = MAXU + 1;
		int smallest_num_index = -1;
		///Find smallest num in original set
		for(int i = 0; i < n; ++i) {
			if(smallest_num > a[i] && !used[i]) {
				smallest_num = a[i];
				smallest_num_index = i;
			}
		}
		if(smallest_num_index == -1)
			break;
		smallest_set[smallest_num_index] = clvl;
		++clvl;
		///Set all the other numbers
		for(int i = 0; i < n; ++i) {
			if(a[i] == a[smallest_num_index]) {
				smallest_set[i] = smallest_set[smallest_num_index];
				used[i] = true;
			}
			else if(a[i] > a[smallest_num_index]) {
				smallest_set[i] = smallest_set[smallest_num_index] + 1;
			}
		}
    }
}

int main() {
	///Input
	cin >> n >> u;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	find_smallest_set();
	find_lex_set();
	for(int i = 0; i < n; ++i) {
		cout << smallest_set[i];
	}
	cout << endl;
	remove_doubles();
	return 0;
}
