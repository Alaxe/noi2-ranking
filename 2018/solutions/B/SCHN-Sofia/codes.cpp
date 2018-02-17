#include <iostream>
#include <vector>
#include <string>

typedef long long ll;

char digits[105];
const ll MAX = 1000000000000000000 + 1;

long long n, k, a, b;

ll stoi(std::string s) {
	ll ret = 0;
	for(int i = 0;i < s.size();i ++) {
		ret *= 10;
		ret += (s[i] - '0');
	}
	return ret;
}
ll sum(std::string s) {
	ll ret = 0;
	for(int i = s.size()-1;i >= 0;i --) {
		ret += (s[i] - '0');
	}
	return ret;
}

std::vector<std::string> generate(std::vector<std::string> prev, std::vector<char> digits) {
	std::vector<std::string> next;
	for(int i = 0;i < digits.size();++ i) {
		if(i % 2 == 0) {
			for(int j = 0;j < prev.size();++ j) {
				next.push_back(digits[i] + prev[j]);
			}
		} else {
			for(int j = prev.size() - 1;j >= 0;-- j) {
				next.push_back(digits[i] + prev[j]);
			}
		}
	}
	return next;
}


int main() {
	std::cin >> n >> k >> a >> b;
	a--;
	b--;

	std::vector<char> digits;
	std::vector<std::string> prev;

	for(ll i = 0;i < n;++ i) {
		char c;
		std::cin >> c;
		digits.push_back(c);
		std::string s = "";
		s += c;
		prev.push_back(s);
	}

	for(int i = 1;i < k;++ i) {
		prev = generate(prev, digits);
	}

	ll ans1 = 0;
	for(int i = a;i <= b;++ i) {
		ll num = stoi(prev[i]);
		if(num > ans1) ans1 = num;
	}

	ll ans2 = 0;
	for(int i = a;i < b;++ i) {
		ll s1 = sum(prev[i]);
		ll s2 = sum(prev[i+1]);
		int as = (s1 < s2 ? s2-s1 : s1-s2);
		if(as > ans2) ans2 = as;
	}


	std::cout << ans1 << ' ';
	std::cout << ans2 << std::endl;
}
