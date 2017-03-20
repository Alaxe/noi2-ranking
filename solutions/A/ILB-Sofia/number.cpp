#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using std::string;

string sum(string a, string b) {
	string r;

	int carry = 0;

	int i = a.length() - 1, j = b.length() - 1;

	while(i >= 0 && j >= 0) {
		int s = a[i] - '0' + b[j] - '0' + carry;
		r += char(s % 10 + '0');
		carry = s / 10;
		--i;
		--j;

		//std::cout << r << std::endl;
	}

	while(i >= 0) {
		int s = a[i] - '0' + carry;

		r += char(s % 10 + '0');
		carry = s / 10;
		--i;
		//std::cout << "#" << r << std::endl;
	}

	while(j >= 0) {
		int s = b[j] - '0' + carry;

		r += char(s % 10 + '0');
		carry = s / 10;
		--j;

		//std::cout << "@" << r << std::endl;
	}

	if (carry > 0) {
		 r += char(carry + '0');
	}

	std::reverse(r.begin(), r.end());
	return r;
}



string mul(string x, int y) {
	string r;
	int carry = 0;

	int i = x.length() - 1;
	while(i >= 0) {
		int s = (x[i] - '0') * y + carry;

		r += char(s % 10 + '0');
		carry = s / 10;
		--i;
	}

	if (carry > 0) {
		 r += char(carry + '0');
	}

	std::reverse(r.begin(), r.end());
	i = 0;
	while(i < r.length() && r[i] == '0') i++;
	if (i == r.length()) i--;
	return r.substr(i, r.length() - i);
}

string mul(string a, string b) {
	string add = "";

	int i = b.length() - 1;
	string r = "0";
	while(i >= 0) {
		r = sum(r, mul(a, b[i] - '0') + add);
		add += "0";
		--i;
	}
	return r;
}


string div2(string x) {

	if (x.length() < 2) {
		string r;
		r += char((x[0] - '0') / 2 + '0');
		return r;
	}

	string r;
	int carry = 0;

	int ldig = x[x.length() - 1] - '0';
	if (ldig % 2)
		x[x.length() - 1]--;

	int cur = x[0] - '0';
	int j = 1;
	if (cur == 1) {
		cur = cur * 10 + x[1] - '0';
		j = 2;
	}

	while(j <= x.length()) {
		r += char(cur / 2 + '0');
		if (cur % 2) { // won't happen at last digit, we have made it even
			cur = 10;
			if (j != x.length())
				cur += x[j] - '0';
		} else {
			if (j != x.length())
				cur = x[j] - '0';
		}
		++j;
	}

	return r;
}


string sub(string a, string b) {
	string r;

	int i = a.length() - 1, j = b.length() - 1;

	int carry = 0;

	while(i >= 0 && j >= 0) {
		int ad = a[i] - '0' + carry, bd = b[j] - '0';
		carry = 0;

		if (ad < bd) {
			carry = -1;
			ad += 10;
		}

		r += char(ad - bd + '0');
		--i, --j;
	}

	while(i >= 0) {
		int ad = a[i] - '0' + carry;
		carry = 0;

		if (ad < 0) {
			carry = -1;
			ad += 10;
		}

		r += char(ad + '0');
		--i;
	}

	std::reverse(r.begin(), r.end());
	i = 0;

	while(i < r.length() && r[i] == '0') i++;
	if (i == r.length()) i--;
	return r.substr(i, r.length() - i);
}

bool isless(string a, string b) {
	if (a.length() < b.length())
		return true;
	else if (a.length() > b.length())
		return false;

	size_t i = 0;
	while(i < a.length()) {
		if (a[i] < b[i])
			return true;
		else if (a[i] > b[i])
			return false;
		++i;
	}
	return false;
}

bool islesseq(string a, string b) {
	if (a.length() < b.length())
		return true;
	else if (a.length() > b.length())
		return false;

	size_t i = 0;
	while(i < a.length()) {
		if (a[i] < b[i])
			return true;
		else if (a[i] > b[i])
			return false;
		++i;
	}
	return true;
}

string tostr(int x) {
	string r;

	while(x > 0) {
		r = char(x % 10 + '0') + r;
		x /= 10;
	}
	return r;
}

string fsqrt(string x, bool lesser) {
	string l = "1", r = "1000000000000000000000000000000000000000000000000000"; // 10^51 ;
	string quot = "1";
	while(isless(l, sub(r, quot))) {
		string mid = div2(sum(l, r));

		//std::cout << mid << std::endl;
		//string mm = mul(mid, mid);
		//std::cout << mm << std::endl;
		if (islesseq(mul(mid, mid), x)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	if (mul(l, l) == x)
		return l;
	else if (!lesser) // do we floor or ceil?
		return sum(l, "1");
	else
		return l;
}

int main() {
	std::ios::sync_with_stdio(false);
	//std::cout << sub("152", "8");

	//std::ifstream inp("text.txt");
	string a, b;
	std::cin >> a >> b;

	string x, y;
	x = sum(mul(a, 4), "1");
	y = sum(mul(b, 4), "1");


	string sqx = fsqrt(x, false);
	string sqy = fsqrt(y, true);

	//std::cout << sqx << " " << sqy << std::endl;

	string fromx = div2(sqx);
	string fromy = div2(sub(sqy, "1"));
	//string fromy = div2(sqy);
	//std::cout << fromx << " " << fromy << std::endl;
	if (!islesseq(fromx, fromy)) {
		std::cout << 0 << std::endl;
		return 0;
	}
	std::cout << sum(sub(fromy, fromx), "1") << std::endl;

	return 0;
}
