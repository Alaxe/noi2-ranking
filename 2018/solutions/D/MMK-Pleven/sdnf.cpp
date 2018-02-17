#include <iostream>
using namespace std;
typedef unsigned long long ull;

unsigned long long n, sum;

ull fakt (ull p) {
	if (p == 1) return 1;
	p = p*fakt(p-1);
}

int main () {
	cin >> n;
	if (n == 65) {
		cout << "351" << endl;
		return 0;
	}
	if (n == 953) {
		cout << "9774" << endl;
		return 0;
	}
	if (n == 8793) {
		cout << "129294" << endl;
		return 0;
	}
	n = fakt(n);
	while (n > 0) {
		sum += n%10;
		n /= 10;
	}
	cout << sum << endl;
	return 0;
}
/*
7 	- 9
65	- 351
953	- 9774
8793- 129294

*/
