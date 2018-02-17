///Not Liberty City Stories though :(

#include <cstdio>
#include <deque>
#include <utility>

typedef unsigned uint32_t;
typedef unsigned long long uint64_t;
typedef int int32_t;
typedef long long int64_t;

typedef std::pair<uint64_t, uint64_t> up32_t;

struct Generator {
private:
	uint64_t cur, mul, add, mod;
public:
	void read() {
		scanf("%llu %llu %llu %llu", &cur, &mul, &add, &mod);
	}
	uint32_t gen() {
		uint32_t ans = cur;
		cur = (cur * mul + add) % mod;
		return ans;
	}
};

uint32_t n, k;
Generator stories;

void input() {
	scanf("%u %u", &n, &k);
	stories.read();
}

int main() {
	input();
	std::deque<up32_t> next;
	uint64_t ans = 0;
	for (uint32_t i = 0;i < n;i++) {
		while ((!next.empty()) && (next.front().first <= i)) {
			next.pop_front();
		}
		uint32_t curStory = stories.gen();;
		while ((!next.empty()) && (next.back().second <= curStory)) {
			next.pop_back();
		}

		next.push_back(up32_t(i + k, curStory));
		ans += next.front().second;
	}

	printf("%llu\n", ans);
}
