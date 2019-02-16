#include <iostream>
#include <cstdint>
#include <algorithm>

const uint32_t MAX_X = 2e5;

template <size_t N>
class SegmentTree {
private:
	uint32_t val[N * 2];
	uint32_t lazy[N];
	uint32_t depth;

	inline void update(uint32_t n, uint32_t v) {
		val[n] = v;
		if (n < N) {
			lazy[n] = v;
		}
	}
	inline void recalc(uint32_t n) {
		if (lazy[n]) {
			val[n] = lazy[n];
		} else {
			val[n] = std::min(val[n * 2], val[n * 2 + 1]);
		}
	}
	inline void push_lazy(uint32_t n) {
		for (uint32_t i = depth;i > 0;i--) {
			uint32_t c = n >> i;
			if (c == 0) {
				continue;
			}
			if (lazy[c]) {
				update(c * 2, lazy[c]);
				update(c * 2 + 1, lazy[c]);
				lazy[c] = 0;
			}
		}
	}
	inline void push_updates(uint32_t n) {
		for (n >>= 1; n > 0; n >>= 1) {
			recalc(n);
		}
	}
	inline void calc_depth() {
		uint32_t n = N >> 1;
		depth = 0;
		while (n > 0) {
			depth++;
			n >>= 1;
		}
	}
public:
	SegmentTree() {
		calc_depth();
		std::fill(lazy, lazy + N, 0);
		std::fill(val, val + 2 * N, 0);
	}

	void update(uint32_t l, uint32_t r, uint32_t v) {
		uint32_t oL = l + N;
		uint32_t oR = r + N;
		push_lazy(oL);
		push_lazy(oR - 1);

		for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
			if (l & 1) {
				update(l++, v);
			}
			if (r & 1) {
				update(--r, v);
			}
		}
		push_updates(oL);
		push_updates(oR - 1);
	}

	uint32_t query(uint32_t l, uint32_t r) {
		l += N;
		r += N;
		push_lazy(l);
		push_lazy(r - 1);

		uint32_t ans = MAX_X * 10;
		for (;l < r;l >>= 1, r >>= 1) {
			if (l & 1) {
				ans = std::min(ans, val[l++]);
			}
			if (r & 1) {
				ans = std::min(ans, val[--r]);
			}
		}
		return ans;
	}
};



SegmentTree<MAX_X> segTree;

struct Segment {
	uint32_t x1, x2;
	uint32_t y;

	friend bool operator< (const Segment &a, const Segment &b) {
		return a.y < b.y;
	}
};

std::vector<Segment> segs;
void read_segments() {
	uint32_t n;
	std::cin >> n;
	segs.resize(n);
	for (Segment &i : segs) {
		std::cin >> i.x1 >> i.y >> i.x2;
		i.x2 = i.x2 + i.x1 - 1;
	}
}

void build_tree() {
	std::sort(segs.begin(), segs.end());
	for (const Segment &i : segs) {
		uint32_t a1 = segTree.query(i.x1 - 1, i.x1);
		uint32_t a2 = segTree.query(i.x2 + 1, i.x2 + 2);
		uint32_t a = std::min(a1, a2) + 1;
		segTree.update(i.x1, i.x2 + 1, a);
		//std::cerr << "Segment " << i.x1 << "; " << i.x2 << "; " << i.y << ":  " << a << "\n";
	}
}

void answer_queries() {
	uint32_t qCnt;
	std::cin >> qCnt;
	for (uint32_t i = 0;i < qCnt;i++) {
		uint32_t a;
		std::cin >> a;
		std::cout << segTree.query(a, a + 1) << " ";
	}
	std::cout << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	read_segments();
	build_tree();
	answer_queries();
}
/**
13
1 4 2
9 5 2
8 1 5
2 2 2
6 2 2
2 6 3
1 3 1
4 3 2
9 3 3
5 4 5
4 5 2
7 5 1
8 6 2
5
2 5 7 8 11
*/
