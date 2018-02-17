#include <iostream>

using namespace std;

int n, m, add, rem;
int ans;

void rec(bool paction, int cmass);

int main()
{
	cin >> m >> n >> add >> rem;

	if(m + add >= n)
		cout << 1 << endl;
	else
	{
		rec(0, m + add);
		cout << ans << endl;
	}


	return 0;
}

void rec(bool paction, int cmass)
{
	if(paction == 1)
	{
		if(cmass + add >= n)
		{
			ans++;
		}
		else
		{
			rec(0, cmass + add);
		}
	}
	else
	{
		if(cmass + add >= n)
		{
			ans++;
			rec(1, cmass - rem);
		}
		else
		{
			rec(0, cmass + add);
			rec(1, cmass - rem);
		}
	}
}
