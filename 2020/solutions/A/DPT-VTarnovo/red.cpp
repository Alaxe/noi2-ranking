#include <bits/stdc++.h>

using namespace std;

#define MAX 110000
#define MOD1 1000000021
#define MOD2 1000000009
#define MOD3 1000000007

long long w, k, n, m, a, pr, br, hj;

long long h1, h2, h3, pows1[MAX], pows2[MAX], pows3[MAX], m1[MAX], m2[MAX], ans;

long long has(long long h, long long ch, long long mod, long long base)
{
	h = h * base;
	h %= mod;
	h += ch;
	h %= mod;
	return h;
}

map< pair<long long, pair<long long, long long> >, int > mp;

int main()
{
	scanf("%d%d",&w,&k);
	pows1[0] = pows2[0] = pows3[0] = 1;
	for(int i = 1; i <= k; i++)
	{
		pows1[i] = pows1[i - 1] * 20 * MAX ;
		pows2[i] = pows2[i - 1] * (20 * MAX + 1);
		pows3[i] = pows3[i - 1] * (20 * MAX + 2);
		pows1[i] %= MOD1;
		pows2[i] %= MOD2;
		pows3[i] %= MOD3;
	}
	scanf("%d", &n);
	pr = 109080078245;
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&a);
		m1[i] = a;
		if(w == 1)
		{
			if(a > pr)
			{
				h1 = has(h1, a, MOD1, 20 * MAX);
				h2 = has(h2, a, MOD2, 20 * MAX + 1);
				h3 = has(h3, a, MOD3, 20 * MAX + 2);
				br++;
			}
			else
			{
				h1 = h2 = h3 = a;
				br = 1;
			}
		}
		else
		{
			if(a == pr)
			{
				h1 = has(h1, a, MOD1, 20 * MAX);

				h2 = has(h2, a, MOD2, 20 * MAX + 1);
				h3 = has(h3, a, MOD3, 20 * MAX + 2);
				br++;
			}
			else
			{
				br = 1;
				h1 = h2 = h3 = a;
			}
		}
		pr = a;
		if(br == k)
		{
			br--;
			mp[{h1, {h2, h3}}]++;
			h1 -= (m1[i - k + 1] * pows1[k - 1]);
			hj = MAX;
			hj *= MOD1;
			h1 += hj;
			h1 %= MOD1;
			h2 -= (m1[i - k + 1] * pows2[k - 1]);
			hj = MAX;
			hj *= MOD2;
			h2 += hj;
			h2 %= MOD2;
			h3 -= (m1[i - k + 1] * pows3[k - 1]);
			hj = MAX;
			hj *= MOD3;
			h3 += hj;
			h3 %= MOD3;
		}
	}

	pr = 10408080894;
	h1 = h2 = h3 = 0;
	br = 1;
	scanf("%lld", &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%lld",&m2[i]);
		a = m2[i];
		if(w == 1)
		{
			if(a > pr)
			{
				h1 = has(h1, a, MOD1, 20 * MAX);
				h2 = has(h2, a, MOD2, 20 * MAX + 1);
				h3 = has(h3, a, MOD3, 20 * MAX + 2);
				br++;
			}
			else
			{
				h1 = h2 = h3 = a;
				br = 1;
			}
		}
		else
		{
			if(a == pr)
			{
				h1 = has(h1, a, MOD1, 20 * MAX);
				h2 = has(h2, a, MOD2, 20 * MAX + 1);
				h3 = has(h3, a, MOD3, 20 * MAX + 2);
				br++;
			}
			else
			{
				br = 1;
				h1 = h2 = h3 = a;
			}
		}
		pr = a;
		if(br == k)
		{

			br--;
			ans += mp[{h1, {h2, h3}}];
			h1 -= (m2[i - k + 1] * pows1[k - 1]);
			hj = MAX;
			hj *= MOD1;
			h1 += hj;
			h1 %= MOD1;
			h2 -= (m2[i - k + 1] * pows2[k - 1]);
			hj = MAX;
			hj *= MOD2;
			h2 += hj;
			h2 %= MOD2;
			h3 -= (m2[i - k + 1] * pows3[k - 1]);
			hj = MAX;
			hj *= MOD3;
			h3 += hj;
			h3 %= MOD3;
		}
	}
	cout << ans << endl;
	return 0;

}
/*

2 3
9
4 4 4 4 4 4 4 4 4
10
4 4 4 4 5 4 4 4 4 4

*/
