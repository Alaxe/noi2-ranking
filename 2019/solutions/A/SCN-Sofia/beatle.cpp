#include <iostream>
#include <algorithm>
//#pragma GCC optimize "Ofast"

const int MAX_N = 1e5 + 10;
const int MAX_X = 2e5 + 10;
int n;

struct Line {
	int x, y, d;
	bool operator<(const Line &other) const {
		return this->y < other.y;
	}
} line[MAX_N];

struct TE {
	int value = 0;
	int prop  = -1;
} tree[MAX_X * 4];

int offset = 1;

#define L(x) (x*2)
#define R(x) (x*2+1)
#define NONLEAF(x) (cfrom != cto)

void updateTree(int qfrom, int qto, int val, int curr, int cfrom, int cto) {
	//std::cout << "ut " << qfrom << ' ' << qto << ' ' << curr << ' ' << cfrom << ' ' << cto << std::endl;

	// fully out
	if(qto < cfrom or cto < qfrom) { return; }

	// fully in
	if(qfrom <= cfrom and qto >= cto) {
		//std::cout << "full in" << std::endl;
		tree[curr].prop = val;
		return;
	}

	if(tree[curr].prop != -1) {
		tree[curr].value = tree[curr].prop;
		if(NONLEAF(curr)) {
			tree[L(curr)].prop = tree[curr].prop;
			tree[R(curr)].prop = tree[curr].prop;
		}
		tree[curr].prop = -1;
	}

	const int mid = (cfrom + cto) / 2;
	updateTree(qfrom, qto, val, L(curr), cfrom, mid);
	updateTree(qfrom, qto, val, R(curr), mid+1, cto);
}

int queryTree(int qfrom, int qto, int curr, int cfrom, int cto) {
	//std::cout << "qt " << qfrom << ' ' << qto << ' ' << curr << ' ' << cfrom << ' ' << cto << std::endl;

	if(qto < cfrom or cto < qfrom) { return -2; }

	if(tree[curr].prop != -1) {
		tree[curr].value = tree[curr].prop;
		if(NONLEAF(curr)) {
			tree[L(curr)].prop = tree[curr].prop;
			tree[R(curr)].prop = tree[curr].prop;
		}
		tree[curr].prop = -1;
	}

	if(qfrom <= cfrom and qto >= cto) {
		return tree[curr].value;
	}

	const int mid = (cfrom + cto) / 2;
	const int v1 = queryTree(qfrom, qto, L(curr), cfrom, mid);
	const int v2 = queryTree(qfrom, qto, R(curr), mid+1, cto);
	return std::max(v1, v2);
}

int query(int x) {
	return queryTree(offset + x, offset + x, 1, offset, offset * 2 - 1);
}

void update(int x, int y, int z) {
	updateTree(offset + x, offset + y, z, 1, offset, offset * 2 - 1);
}

int main() {
	#ifndef LOCAL_STJO
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	#endif

	// TODO test for x=16
	while(offset <= MAX_X) {
		offset *= 2;
	}

/*
	while(true) {
		int a, x, y, z;
		std::cin >> a;
		if(a == 0) {
			std::cin >> x >> y >> z;
			updateTree(offset + x, offset + y, z, 1, offset, offset * 2 - 1);
		}
		if(a == 1) {
			std::cin >> x >> y;
			std::cout << queryTree(offset + x, offset + y, 1, offset, offset * 2 - 1) << std::endl;
		}
	}
	*/

	std::cin >> n;

	for(int i = 0;i < n;i ++) std::cin >> line[i].x >> line[i].y >> line[i].d;
	std::sort(line, line + n);

	for(int i = 0;i < n;i ++) {
		const int v = std::min(query(line[i].x - 1), query(line[i].x + line[i].d)) + 1;
		update(line[i].x, line[i].x + line[i].d - 1, v);
	}

/*
	for(int i = 0;i < 16;i ++) {
		std::cout << query(i) << ' ';
	}
	*/

	int T;
	std::cin >> T;
	while(T --> 0) {
		int x;
		std::cin >> x;
		std::cout << query(x) << ' ';
	}
	return 0;
}
