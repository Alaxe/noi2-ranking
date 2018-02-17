#include <iostream>

const int MAXN = 11000;

struct Square {
	int x, y, w, h;
} squares[MAXN];

int sqCount;

int surface(Square &sq) {
	return sq.w * sq.h;
}

int findSmallest(int x, int y) {
	int idx = -1, minSurf = (1 << 30);
	for(int i = 0;i < sqCount;i ++) {
		if(squares[i].x <= x and squares[i].x + squares[i].w >= x
			and squares[i].y <= y and squares[i].y + squares[i].h >= y) {
			int ns = surface(squares[i]);
			if(ns < minSurf) {
				idx = i;
				minSurf = ns;
			}
		}
	}
	return idx;
}

inline bool inside(Square &in, Square &out) {
	return in.x >= out.x and in.y >= out.y
	and in.x + in.w <= out.x + out.w and in.y + in.h < out.y + out.h;
}

int ans(int x, int y) {
	int outer = findSmallest(x, y);
	int sml[MAXN], count = 0;
	for(int i = 0;i < sqCount;i ++) {
		if(i != outer and inside(squares[i], squares[outer])) {
			bool fail = false;
			for(int j = 0;j < count;j ++) {
				if(inside(squares[i], squares[sml[j]])) {
					fail = true;
					break;
				}
				if(inside(squares[sml[j]], squares[i])) {
					std::swap(sml[j], sml[count-1]);
					count --;
				}
			}
			if(!fail) sml[count ++] = i;
		}
	}

	int out = surface(squares[outer]);
	for(int j = 0;j < count;j ++) {
		out -= surface(squares[sml[j]]);
	}
	return out;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	squares[0].x = 0;
	squares[0].y = 0;
	std::cin >> squares[0].w >> squares[0].h;

	std::cin >> sqCount;
	sqCount ++;
	for(int i = 1;i < sqCount;i ++) {
		std::cin >> squares[i].x >> squares[i].y >> squares[i].w >> squares[i].h;
	}

	int queries;
	std::cin >> queries;
	for(int i = 0;i < queries;i ++) {
		int x, y;
		std::cin >> x >> y;
		std::cout << ans(x, y) << '\n';
	}
	return 0;
}
