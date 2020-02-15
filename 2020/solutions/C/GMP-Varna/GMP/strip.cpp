#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, k;
long long a[55], ans;

int main ()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	a[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		a[i] = 1;
		for (int j = i-1; j ; j--)
			a[j] += a[j-1];
	}

	ans = a[k];

	cout << ans << endl;

	return 0;
}
/**
4
2
======
5
1
*/
