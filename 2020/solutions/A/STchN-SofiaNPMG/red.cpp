#include <iostream>
#include <vector>
#include <unordered_map>
using std::cin; using std::cout; using std::endl;
typedef unsigned long long ull;

int W, K;
ull answer;
std::vector<int> A, B;
//const ull MOD = 120000007; //125000000 + 3;
std::unordered_map<ull, int> seen;
//int seen[MOD];

void input() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> W >> K;
	int x;

	// A
	std::cin >> x;
	A.resize(x);
	for(int i = 0;i < x;i ++) std::cin >> A[i];

	// B
	std::cin >> x;
	B.resize(x);
	for(int i = 0;i < x;i ++) std::cin >> B[i];
}

void compute(const std::vector<int> &V, int mul) {
	const ull BASE = 5000029;

	ull POWBASE = 1;
	for(int i = 0;i < K-1;i ++) POWBASE *= BASE;
	
	ull curHash = V[0];
	const int Vs = V.size(); // I don't trust the compiler nor the stl :D
	int lastIdxPropBroken = -1;

	if(K == 1) { // omg, took me so long to find this edge case
		answer        += mul * (seen[curHash]);
		seen[curHash] += !mul;
	}

	for(int i = 1;i < Vs;i ++) {
		if(W == 1) { if(V[i-1] >= V[i]) lastIdxPropBroken = i-1; }
		else       { if(V[i-1] != V[i]) lastIdxPropBroken = i-1; }

		if(i >= K) curHash -= V[i-K] * POWBASE;
		curHash *= BASE;
		curHash += V[i];
		//curHash %= MOD;

		//std::cout << "main loop i=" << i << " curHash=" << curHash << " lipb=" << lastIdxPropBroken << std::endl;
		if(i - lastIdxPropBroken >= K) {
			//std::cout << "mark" << std::endl;
			// branchless if(mul) {} else {}
			answer        += mul * (seen[curHash]);
			seen[curHash] += !mul;
		}
	}
}

void solution() {
	compute(A, 0);
	compute(B, 1);
	std::cout << answer << std::endl;
}

int main() {
	input();
	solution();
	return 0;
}
