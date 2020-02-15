#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


const int MAXN = 200000;///200 000

string eq;

void id_outer_brackets(string s) {
	int num_left = 0;
	int num_right = 0;
	int first_left_index = -1;
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] == '(') {
			if(num_left == 0)
				first_left_index = i;
			++num_left;
		}
		if(s[i] == ')')
			++num_right;
		if(num_left == num_right && num_left != 0) {
			for(int j = first_left_index; j <= i; ++j) {
				cout << s[j];
			}
			cout << endl;
			if(s[first_left_index - 1] == 0)
			num_left = 0;
			num_right = 0;
		}
	}
}

int main() {
	cin >> eq;
	eq = "1" + eq + "1";
	id_outer_brackets(eq);

	return 0;
}
