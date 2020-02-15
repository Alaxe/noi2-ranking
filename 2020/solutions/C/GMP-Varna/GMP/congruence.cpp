#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string s;

int main ()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s;

	int L = s.size();

	string p = s;
	sort(p.begin(), p.end());

	p += '*';

	string t = s;

	int k = 0;

	for (int i = 0; i < L; i++)
	{
		if (p[i] == p[i+1]) continue;

		k++;

		for (int j = 0; j < L; j++)
			if (s[j] == p[i])
				t[j] = k;
	}

	for (int i = 0; i < L; i++)
	{
		cout << (char)(t[i]+'A'-1);
		t[i] -= k;
	}
	cout << endl;
	for (int i = 0; i < L; i++)
	{
		cout << (char)(t[i]+'Z');
	}
	cout << endl;
	return 0;
}
/**
ABBA
=====
KOMAP
*/
