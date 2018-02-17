#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>


typedef unsigned uint32_t;
typedef unsigned long long uint64_t;
typedef int int32_t;
//typedef long long int64_t;

///The length is given in inches
const uint32_t MAX_LEN = 102;
const uint32_t BASE = 10;

class KrasiManev {
private:
	uint32_t dig[3 * MAX_LEN];
	uint32_t len;

	void trim() {
		while ((len > 1) && (dig[len - 1] == 0)) {
			len--;
		}
	}
	void set_uint(uint64_t n = 0) {
		memset(dig, 0, sizeof(dig));
		len = 0;

		if (n == 0) {
			len = 1;
			dig[0] = 0;
		}
		while (n) {
			dig[len] = n % 10;
			n /= 10;
			len++;
		}
	}
public:
	KrasiManev(uint64_t val = 0) {
		set_uint(val);
	}

	void read() {
		char s[MAX_LEN];
		scanf("%s", s);
		len = strlen(s);
		for (uint32_t i = 0;i < len;i++) {
			dig[i] = s[len - i - 1] - '0';
		}
	}

	void print() {
		for (uint32_t i = 0;i < len;i++) {
			printf("%u", dig[len - i - 1]);
		}
		printf("\n");
	}

	KrasiManev& operator = (const KrasiManev &n) {
		len = n.len;
		memcpy(dig, n.dig, sizeof(dig));
		return *this;
	}
	KrasiManev& operator = (uint64_t n) {
		set_uint(n);
		return *this;
	}

	KrasiManev& operator += (const KrasiManev &n) {
		len = std::max(len, n.len) + 1;
		for (uint32_t i = 0;i < len;i++) {
			dig[i] += n.dig[i];
			if (dig[i] >= BASE) {
				dig[i] -= BASE;
				dig[i + 1]++;
			}
		}

		trim();
		return *this;
	}
	friend KrasiManev operator + (KrasiManev a, const KrasiManev &b) {
		return a += b;
	}
	KrasiManev& operator -= (const KrasiManev &n) {
		for (uint32_t i = 0;i < len;i++) {
			if ((dig[i] > BASE) || (dig[i] < n.dig[i])) {
				dig[i] += BASE;
				dig[i + 1]--;
			}
			dig[i] -= n.dig[i];
		}
		trim();
		return *this;
	}
	friend KrasiManev operator - (KrasiManev a, const KrasiManev &b) {
		return a -= b;
	}

	KrasiManev& operator *= (uint32_t a) {
		for (uint32_t i = 0;i < len;i++) {
			dig[i] *= a;
		}
		len += 20;
		for (uint32_t i = 1;i < len;i++) {
			dig[i] += dig[i - 1] / BASE;
			dig[i - 1] %= BASE;
		}
		trim();
		return *this;
	}
	friend KrasiManev operator * (KrasiManev a, uint32_t b) {
		return a *= b;
	}

	friend KrasiManev operator * (const KrasiManev &a, const KrasiManev &b) {
		KrasiManev ans;
		ans.len = a.len + b.len;
		for (uint32_t i = 0;i < a.len;i++) {
			for (uint32_t j = 0;j < b.len;j++) {
				ans.dig[i + j] += a.dig[i] * b.dig[j];
			}
		}
		for (uint32_t i = 1;i < ans.len;i++) {
			ans.dig[i] += ans.dig[i - 1] / BASE;
			ans.dig[i - 1] %= BASE;
		}
		ans.trim();
		return ans;
	}

	bool friend operator < (const KrasiManev &a, const KrasiManev &b) {
		if (a.len != b.len) {
			return a.len < b.len;
		}
		for (int32_t i = a.len;i >= 0;i--) {
			if (a.dig[i] != b.dig[i]) {
				return a.dig[i] < b.dig[i];
			}
		}
		return false;
	}
	bool friend operator <= (const KrasiManev &a, const KrasiManev &b) {
		return !(b < a);
	}
	bool friend operator > (const KrasiManev &a, const KrasiManev &b) {
		return b < a;
	}
	bool friend operator >= (const KrasiManev &a, const KrasiManev &b) {
		return !(a < b);
	}
	bool friend operator == (const KrasiManev &a, const KrasiManev &b) {
		if (a.len != b.len) {
			return false;
		}
		for (uint32_t i = 0;i < a.len;i++) {
			if (a.dig[i] != b.dig[i]) {
				return false;
			}
		}
		return true;
	}
	bool friend operator != (const KrasiManev &a, const KrasiManev &b) {
		return !(a == b);
	}
};

KrasiManev basePowers[MAX_LEN];
void calc_base_powers() {
	basePowers[0] = 1;
	//basePowers[0].print();
	for (uint32_t i = 1;i < MAX_LEN;i++) {
		//printf("hello\n");
		basePowers[i] = basePowers[i - 1] * 10;
		//basePowers[i].print();
	}
}

KrasiManev smaller_cnt(const KrasiManev &num) {
	KrasiManev ans = 0;
	KrasiManev modified;
	KrasiManev guess;
	for (int32_t pos = MAX_LEN - 1;pos >= 0;pos--) {
		modified = ans;
		while (true) {
			modified += basePowers[pos];
			//modified.print();
			guess = modified * modified + modified;
			//guess.print();
			//printf("\n");
			if (guess < num) {
				ans = modified;
			} else {
				break;
			}
		}
	}
	return ans;
}


int main() {
	calc_base_powers();
	KrasiManev low, high;

	low.read();
	high.read();

	high += 1;
	//high.print();

	KrasiManev lowCnt = smaller_cnt(low);
	KrasiManev highCnt = smaller_cnt(high);

	KrasiManev ans = highCnt - lowCnt;
	ans.print();
}
