#include <iostream>
#include <cstdint>
#include <vector>

std::vector<uint32_t> num;
std::vector<uint32_t> ans;

uint32_t base; //NaOH

void read_num() {
	std::string s;
	std::cin >> s;
	num.clear();
	for (uint32_t i = s.size() - 1;i < s.size();i--) {
		if ((s[i] >= '0') && (s[i] <= '9')) {
			num.push_back(s[i] - '0');
		} else {
			num.push_back(s[i] - 'A' + 10);
		}
	}
}

bool div_num(uint32_t k) {
	uint32_t mod = 0;
	for (uint32_t i = num.size() - 1;i < num.size();i--) {
		mod = mod * base + num[i];
		num[i] = mod / k;
		mod %= k;
	}

	while ((num.size() > 1) && (num.back() == 0)) {
		num.pop_back();
	}
	//print_v(num);
	return mod == 0;
}
uint32_t ans_len() {
	for (uint32_t i = num.size() - 1;i < num.size();i--) {
		if (num[i] > base - 2) {
			return num.size() + 2;
		} else if (num[i] < base - 2) {
			return num.size() + 1;
		}
	}
	return num.size() + 1;
}

void calc_ans(uint32_t len) {
	ans.resize(len);
	for (uint32_t i = 0;i < len;i++) {
		ans[i] = 1;
	}
	//print_v(ans);
	for (uint32_t i = 0;i < num.size();i++) {
		ans[i] += num[i];
	}
	//print_v(ans);
	for (uint32_t i = 0;i < len;i++) {
		if (ans[i] >= base) {
			ans[i + 1] += ans[i] / base;
			ans[i] %= base;

		}
	}
}

void print_ans() {
	for (uint32_t i = ans.size() - 1;i < ans.size();i--) {
		if (ans[i] < 10) {
			std::cout << (char)(ans[i] + '0');
		} else {
			std::cout << (char)(ans[i] + 'A' - 10);
		}
	}
	std::cout << "\n";
}

void solve() {
	read_num();

	if (!div_num(base - 1)) {
		std::cout << 0 << "\n";
		return;
	}
	uint32_t l = ans_len();
	calc_ans(l);
	print_ans();
}

int main() {
	std::cin >> base;
	for (uint32_t i = 0;i < 4;i++) {
		solve();
	}
}
