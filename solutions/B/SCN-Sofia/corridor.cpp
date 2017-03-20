#include <iostream>
#include <algorithm>

const int MAXN = 100000;

struct Line {
	long long x, y1, y2;
	bool operator<(const Line &other) const {
		if(this->y1 != other.y1) return this->y1 < other.y1;
		return this->x < other.x;
	}
} lines[MAXN];
int count = 0;

int fix(int idx) {
	int end = idx;
	while(end+1 < count-1 and lines[end].x < lines[end+1].x) {
		end ++;
	}
	for(int i = 0;i < (end-idx+1) / 2;i ++) {
		std::swap(lines[idx+i], lines[end-i]);
	}
	return end;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	long long w, h;
	int n;
	std::cin >> w >> h >> n;

	long long prvX, prvY;
	std::cin >> prvX >> prvY;
	while(n-- > 1) {
		long long x, y;
		std::cin >> x >> y;
		if(prvX == x) {
			lines[count].x = prvX;
			if(prvY < y) {
				lines[count].y1 = prvY;
				lines[count].y2 = y;
			} else {
				lines[count].y1 = y;
				lines[count].y2 = prvY;
			}
			count ++;
		}
		prvX = x;
		prvY = y;
	}

	std::sort(lines, lines + count);
	lines[count].x = w;
	lines[count].y1 = h;
	lines[count].y2 = h;
	count ++;

	int curr = 0;
	long long ans = 0, cx = 0;
	int noFix = -1;
	for(int i = 1;i < count;i ++) {
		//std::cout << "======" << std::endl;
		//std::cout << lines[curr].x << ' ' << lines[curr].y1 << ' ' << lines[curr].y2 << '\n';
		//std::cout << lines[i].x << ' ' << lines[i].y1 << ' ' << lines[i].y2 << '\n';
		if(lines[curr].x < lines[i].x) {
			if(lines[i].y1 > cx) {
				const long long add = lines[curr].x * (lines[i].y1 - cx);
				//std::cout << "HR " << add << std::endl;
				ans += add;
				cx = lines[i].y1;
			}
		} else {
			if(noFix < i) {
				noFix = fix(i);
				//std::cout << "Fixed from " << i << " to " << noFix << std::endl;
			}
		//std::cout << lines[curr].x << ' ' << lines[curr].y1 << ' ' << lines[curr].y2 << '\n';
		//std::cout << lines[i].x << ' ' << lines[i].y1 << ' ' << lines[i].y2 << '\n';
			const long long add = lines[curr].x * (lines[curr].y2 - cx);
			if(lines[curr].y2 > cx) {
				//std::cout << "SS " << add << std::endl;
				ans += add;
				cx = lines[curr].y2;
			}
		}
		//std::cout << "cx = " << cx << std::endl;
		curr = i;
	}
	std::cout << w*h - ans << '\n';
	return 0;
}
