#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int br[100010] = {0}, n, m, a, b, ans = 0;

int main ()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		br[a]++;
	}

	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		ans = 0;
		cin >> a >> b;
		for (int j = a; j <= b; j++)
			ans += br[j];
		cout << ans << endl;
	}

	return 0;
}
/**
6
9 1 3 10 3 4
3
1 4
9 12
15 20
*/
