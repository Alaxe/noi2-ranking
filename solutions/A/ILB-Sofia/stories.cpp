#include <stdio.h>
const int maxn = 1e7+100;
#define ll long long

struct pair {
	ll x, age;
	pair() {x = age = 0;}
	pair(ll _x, ll _age) {x = _x; age = _age;}
};
pair stack[maxn];
ll ptr = 0, b = 0;
int main() {

	ll n, k, x, mul, add, mod;

	scanf("%lld %lld %lld %lld %lld %lld", &n, &k, &x, &mul, &add, &mod);

	ll total = 0;

	for (ll i = 0; i < n; i++) {
		if (ptr > 0 && stack[b].age <= i - k)
			b++;

		while(ptr > b && stack[ptr - 1].x < x)
			ptr--;

		stack[ptr++] = pair(x, i);

		total += stack[b].x;
		x = ((x * mul) % mod + add) % mod;
	}

	printf("%lld\n", total);
	return 0;
}
